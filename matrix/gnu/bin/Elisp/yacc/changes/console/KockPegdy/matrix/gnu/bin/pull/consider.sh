# From: Nir Soffer <nsoffer@redhat.com>

# When opening an image with discard=off, we punch hole in the image when
# writing zeroes, making the image sparse. This breaks users that want to
# ensure that writes cannot fail with ENOSPACE by using fully allocated
# images[1].

# bdrv_co_pwrite_zeroes() correctly disables BDRV_REQ_MAY_UNMAP if we
# opened the child without discard=unmap or discard=on. But we don't go
# through this function when accessing the top node. Move the check down
# to bdrv_co_do_pwrite_zeroes() which seems to be used in all code paths.

# This change implements the documented behavior, punching holes only when
# opening the image with discard=on or discard=unmap. This may not be the
# best default but can improve it later.

# The test depends on a file system supporting discard, deallocating the
# entire file when punching hole with the length of the entire file.
# Tested with xfs, ext4, and tmpfs.

# [1] https://lists.nongnu.org/archive/html/qemu-discuss/2024-06/msg00003.html

# Signed-off-by: Nir Soffer <nsoffer@redhat.com>
# Message-id: 20240628202058.1964986-3-nsoffer@redhat.com
# Signed-off-by: Stefan Hajnoczi <stefanha@redhat.com>
---
 block/io.c                                    |   9 +-
 tests/qemu-iotests/tests/write-zeroes-unmap   | 127 ++++++++++++++++++
 .../qemu-iotests/tests/write-zeroes-unmap.out |  81 +++++++++++
 3 files changed, 213 insertions(+), 4 deletions(-)
 create mode 100755 tests/qemu-iotests/tests/write-zeroes-unmap
 create mode 100644 tests/qemu-iotests/tests/write-zeroes-unmap.out

diff --git a/block/io.c b/block/io.c
index 7217cf811b..301514c880 100644
--- a/block/io.c
+++ b/block/io.c
@@ -1862,6 +1862,11 @@ bdrv_co_do_pwrite_zeroes(BlockDriverState *bs, int64_t 
offset, int64_t bytes,
         return -EINVAL;
     }
 
+    /* If opened with discard=off we should never unmap. */
+    if (!(bs->open_flags & BDRV_O_UNMAP)) {
+        flags &= ~BDRV_REQ_MAY_UNMAP;
+    }
+
     /* Invalidate the cached block-status data range if this write overlaps */
     bdrv_bsc_invalidate_range(bs, offset, bytes);
 
@@ -2315,10 +2320,6 @@ int coroutine_fn bdrv_co_pwrite_zeroes(BdrvChild *child, 
int64_t offset,
     trace_bdrv_co_pwrite_zeroes(child->bs, offset, bytes, flags);
     assert_bdrv_graph_readable();
 
-    if (!(child->bs->open_flags & BDRV_O_UNMAP)) {
-        flags &= ~BDRV_REQ_MAY_UNMAP;
-    }
-
     return bdrv_co_pwritev(child, offset, bytes, NULL,
                            BDRV_REQ_ZERO_WRITE | flags);
 }
diff --git a/tests/qemu-iotests/tests/write-zeroes-unmap 
b/tests/qemu-iotests/tests/write-zeroes-unmap
new file mode 100755
index 0000000000..7cfeeaf839
--- /dev/null
+++ b/tests/qemu-iotests/tests/write-zeroes-unmap
@@ -0,0 +1,127 @@
+#!/usr/bin/env bash
+# group: quick
+#
+# Test write zeros unmap.
+#
+# Copyright (C) Red Hat, Inc.
+#
+# This program is free software; you can redistribute it and/or modify
+# it under the terms of the GNU General Public License as published by
+# the Free Software Foundation; either version 2 of the License, or
+# (at your option) any later version.
+#
+# This program is distributed in the hope that it will be useful,
+# but WITHOUT ANY WARRANTY; without even the implied warranty of
+# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+# GNU General Public License for more details.
+#
+# You should have received a copy of the GNU General Public License
+# along with this program.  If not, see <http://www.gnu.org/licenses/>.
+#
+
+seq="$(basename $0)"
+echo "QA output created by $seq"
+
+trap _cleanup_test_img exit
+
+# get standard environment, filters and checks
+cd ..
+. ./common.rc
+. ./common.filter
+
+_supported_fmt raw
+_supported_proto file
+_supported_os Linux
+
+create_test_image() {
+    _make_test_img -f $IMGFMT 1m
+}
+
+filter_command() {
+    _filter_testdir | _filter_qemu_io | _filter_qemu | _filter_hmp
+}
+
+print_disk_usage() {
+    du -sh $TEST_IMG | _filter_testdir
+}
+
+echo
+echo "=== defaults - write zeros ==="
+echo
+
+create_test_image
+echo -e 'qemu-io none0 "write -z 0 1m"\nquit' \
+    | $QEMU -monitor stdio -drive if=none,file=$TEST_IMG,format=$IMGFMT \
+    | filter_command
+print_disk_usage
+
+echo
+echo "=== defaults - write zeros unmap ==="
+echo
+
+create_test_image
+echo -e 'qemu-io none0 "write -zu 0 1m"\nquit' \
+    | $QEMU -monitor stdio -drive if=none,file=$TEST_IMG,format=$IMGFMT \
+    | filter_command
+print_disk_usage
+
+
+echo
+echo "=== defaults - write actual zeros ==="
+echo
+
+create_test_image
+echo -e 'qemu-io none0 "write -P 0 0 1m"\nquit' \
+    | $QEMU -monitor stdio -drive if=none,file=$TEST_IMG,format=$IMGFMT \
+    | filter_command
+print_disk_usage
+
+echo
+echo "=== discard=off - write zeroes unmap ==="
+echo
+
+create_test_image
+echo -e 'qemu-io none0 "write -zu 0 1m"\nquit' \
+    | $QEMU -monitor stdio -drive 
if=none,file=$TEST_IMG,format=$IMGFMT,discard=off \
+    | filter_command
+print_disk_usage
+
+echo
+echo "=== detect-zeroes=on - write actual zeros ==="
+echo
+
+create_test_image
+echo -e 'qemu-io none0 "write -P 0 0 1m"\nquit' \
+    | $QEMU -monitor stdio -drive 
if=none,file=$TEST_IMG,format=$IMGFMT,detect-zeroes=on \
+    | filter_command
+print_disk_usage
+
+echo
+echo "=== detect-zeroes=on,discard=on - write actual zeros ==="
+echo
+
+create_test_image
+echo -e 'qemu-io none0 "write -P 0 0 1m"\nquit' \
+    | $QEMU -monitor stdio -drive 
if=none,file=$TEST_IMG,format=$IMGFMT,detect-zeroes=on,discard=on \
+    | filter_command
+print_disk_usage
+
+echo
+echo "=== discard=on - write zeroes ==="
+echo
+
+create_test_image
+echo -e 'qemu-io none0 "write -z 0 1m"\nquit' \
+    | $QEMU -monitor stdio -drive 
if=none,file=$TEST_IMG,format=$IMGFMT,discard=on \
+    | filter_command
+print_disk_usage
+
+echo
+echo "=== discard=on - write zeroes unmap ==="
+echo
+
+create_test_image
+echo -e 'qemu-io none0 "write -zu 0 1m"\nquit' \
+    | $QEMU -monitor stdio -drive 
if=none,file=$TEST_IMG,format=$IMGFMT,discard=on \
+    | filter_command
+print_disk_usage
diff --git a/tests/qemu-iotests/tests/write-zeroes-unmap.out 
b/tests/qemu-iotests/tests/write-zeroes-unmap.out
new file mode 100644
index 0000000000..c931994897
--- /dev/null
+++ b/tests/qemu-iotests/tests/write-zeroes-unmap.out
@@ -0,0 +1,81 @@
+QA output created by write-zeroes-unmap
+
+=== defaults - write zeros ===
+
+Formatting 'TEST_DIR/t.IMGFMT', fmt=IMGFMT size=1048576
+QEMU X.Y.Z monitor - type 'help' for more information
+(qemu) qemu-io none0 "write -z 0 1m"
+wrote 1048576/1048576 bytes at offset 0
+1 MiB, X ops; XX:XX:XX.X (XXX YYY/sec and XXX ops/sec)
+(qemu) quit
+1.0M   TEST_DIR/t.raw
+
+=== defaults - write zeros unmap ===
+
+Formatting 'TEST_DIR/t.IMGFMT', fmt=IMGFMT size=1048576
+QEMU X.Y.Z monitor - type 'help' for more information
+(qemu) qemu-io none0 "write -zu 0 1m"
+wrote 1048576/1048576 bytes at offset 0
+1 MiB, X ops; XX:XX:XX.X (XXX YYY/sec and XXX ops/sec)
+(qemu) quit
+1.0M   TEST_DIR/t.raw
+
+=== defaults - write actual zeros ===
+
+Formatting 'TEST_DIR/t.IMGFMT', fmt=IMGFMT size=1048576
+QEMU X.Y.Z monitor - type 'help' for more information
+(qemu) qemu-io none0 "write -P 0 0 1m"
+wrote 1048576/1048576 bytes at offset 0
+1 MiB, X ops; XX:XX:XX.X (XXX YYY/sec and XXX ops/sec)
+(qemu) quit
+1.0M   TEST_DIR/t.raw
+
+=== discard=off - write zeroes unmap ===
+
+Formatting 'TEST_DIR/t.IMGFMT', fmt=IMGFMT size=1048576
+QEMU X.Y.Z monitor - type 'help' for more information
+(qemu) qemu-io none0 "write -zu 0 1m"
+wrote 1048576/1048576 bytes at offset 0
+1 MiB, X ops; XX:XX:XX.X (XXX YYY/sec and XXX ops/sec)
+(qemu) quit
+1.0M   TEST_DIR/t.raw
+
+=== detect-zeroes=on - write actual zeros ===
+
+Formatting 'TEST_DIR/t.IMGFMT', fmt=IMGFMT size=1048576
+QEMU X.Y.Z monitor - type 'help' for more information
+(qemu) qemu-io none0 "write -P 0 0 1m"
+wrote 1048576/1048576 bytes at offset 0
+1 MiB, X ops; XX:XX:XX.X (XXX YYY/sec and XXX ops/sec)
+(qemu) quit
+1.0M   TEST_DIR/t.raw
+
+=== detect-zeroes=on,discard=on - write actual zeros ===
+
+Formatting 'TEST_DIR/t.IMGFMT', fmt=IMGFMT size=1048576
+QEMU X.Y.Z monitor - type 'help' for more information
+(qemu) qemu-io none0 "write -P 0 0 1m"
+wrote 1048576/1048576 bytes at offset 0
+1 MiB, X ops; XX:XX:XX.X (XXX YYY/sec and XXX ops/sec)
+(qemu) quit
+1.0M   TEST_DIR/t.raw
+
+=== discard=on - write zeroes ===
+
+Formatting 'TEST_DIR/t.IMGFMT', fmt=IMGFMT size=1048576
+QEMU X.Y.Z monitor - type 'help' for more information
+(qemu) qemu-io none0 "write -z 0 1m"
+wrote 1048576/1048576 bytes at offset 0
+1 MiB, X ops; XX:XX:XX.X (XXX YYY/sec and XXX ops/sec)
+(qemu) quit
+1.0M   TEST_DIR/t.raw
+
+=== discard=on - write zeroes unmap ===
+
+Formatting 'TEST_DIR/t.IMGFMT', fmt=IMGFMT size=1048576
+QEMU X.Y.Z monitor - type 'help' for more information
+(qemu) qemu-io none0 "write -zu 0 1m"
+wrote 1048576/1048576 bytes at offset 0
+1 MiB, X ops; XX:XX:XX.X (XXX YYY/sec and XXX ops/sec)
+(qemu) quit
+0      TEST_DIR/t.raw
-- 
2.45.2
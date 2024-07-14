#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdalign.h>

#if 0
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))

#define MALLOC(size) aligned_alloc(alignof(max_align_t), (size))
#define FREE(ptr) free(ptr)


typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int width;
    int height;
} Size;

typedef struct {
    Point origin;
    Size size;
} Rect;


void print_point(const char* prefix, const Point* point) {
    printf("%s: (%d, %d)\n", prefix, point->x, point->y);
}

void print_size(const char* prefix, const Size* size) {
    printf("%s: (%d, %d)\n", prefix, size->width, size->height);
}

void print_rect(const char* prefix, const Rect* rect) {
    printf("%s:\n", prefix);
    print_point("Origin", &rect->origin);
    print_size("Size", &rect->size);
}

void translate_point(Point* point, int dx, int dy) {
    point->x += dx;
    point->y += dy;
}

void scale_point(Point* point, double factor) {
    point->x *= factor;
    point->y *= factor;
}

void translate_rect(Rect* rect, int dx, int dy) {
    translate_point(&rect->origin, dx, dy);
}

void scale_rect(Rect* rect, double factor) {
    scale_point(&rect->origin, factor);
    scale_point(&rect->size, factor);
}

int main() {
    Point p1 = { 10, 20 };
    Point p2 = { 5, 15 };
    print_point("Point 1:", &p1);
    print_point("Point 2:", &p2);

    translate_point(&p1, 5, 10);
    print_point("Translated Point 1:", &p1);

    scale_point(&p1, 2.0);
    print_point("Scaled Point 1:", &p1);


    Size size1 = { 100, 200 };
    Size size2 = { 50, 100 };
    print_size("Size 1:", &size1);
    print_size("Size 2:", &size2);

    scale_point(&size1, 0.5);
    print_size("Scaled Size 1:", &size1);


    Rect rect1 = { {
        100, 200
    }, {
        100, 200
    } };
    print_rect("Rect 1:", &rect1);
    translate_rect(&rect1, 50, 100);
    print_rect("Translated Rect 1:", &rect1);
    scale_rect(&rect1, 0.5);
    print_rect("Scaled Rect 1:", &rect1);
    return 0;
}
#endif
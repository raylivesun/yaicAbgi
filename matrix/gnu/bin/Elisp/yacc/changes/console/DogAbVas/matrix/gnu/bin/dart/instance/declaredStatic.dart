dynamic dependencies = [depend];

mixin depend {
  void initState() {
    update();
    dependencies.add(this);
  }

  dynamic update() => super.toString();

  void dispose() {
    dependencies.remove(this);
    output();
  }

  dynamic output() => super.toString();
}

void main() {
  return update();
}

dynamic update() {
  return Object();
}

depend Object() => dart();

dart() {
  return Object();
}
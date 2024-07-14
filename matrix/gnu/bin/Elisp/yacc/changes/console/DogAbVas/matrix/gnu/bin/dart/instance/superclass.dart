import 'dart:convert';

dynamic edges = graph;

mixin graph {
  late Stream namespace;
  late Stream edges;
  late Stream nodes;
  late Stream graphical;
  late Stream<Map<String, dynamic>> node;
  late Stream<Map<String, dynamic>> edge;
  late Stream<Map<String, dynamic>> graphically;
  late Stream<Map<String, dynamic>> graphic;
  late Stream<Map<String, dynamic>> object;
  late Stream<Map<String, dynamic>> objects;
  late Stream<Map<String, dynamic>> objectGraph;
  late Stream<Map<String, dynamic>> objectGraphs;
  late Stream<Map<String, dynamic>> objectsGraph;
  
}

class Edges extends Encoding implements Object {
  @override
  //  implement decoder
  Converter<List<int>, String> get decoder => throw UnimplementedError();

  @override
  //  implement encoder
  Converter<String, List<int>> get encoder => throw UnimplementedError();

  @override
  //  implement name
  String get name => throw UnimplementedError();

}

void main() {
  var edges = Edges();
  print(edges.decode(edges.encode(graph as String)));
}

import '../../../test/matrix.dart';

var elements = ArgumentError.value(value);

mixin value {
  late String values;
  late List<String> valuesList;
  late Map<String, String> valuesMap;
  late List<Map<String, String>> valuesListMap;
  late Map<String, Map<String, String>> valuesMapMap;
  late List<List<String>> valuesListList;
  late Map<String, List<String>> valuesMapList;
  late List<Map<String, Map<String, String>>> valuesListListMap;
  late Map<String, Map<String, Map<String, String>>> valuesMapListMap;  
}

class ElementList<tokens> {
  late List<tokens> elements;
  late List<List<tokens>> elementsList;
  late List<Map<String, tokens>> elementsMap;
  late List<List<Map<String, tokens>>> elementsListMap;
  late List<Map<String, Map<String, tokens>>> elementsMapList;
  late List<List<List<tokens>>> elementsListList;
} 

void add(String string , MapString stringList) {
  stringList.valuesList.add(string);
}

class MapString {
  late String values;
  
  get valuesList => null;
  
  get valuesMapList => null;
}

void addList(List<String> stringList, ListString stringListList) {
  stringListList.valuesListList.add(stringList);
}

class ListString {
  late List<String> values;
  
  get valuesListList => null;
}

void addMap(Map<String, String> stringMap, MapString stringMapList) {
  stringMapList.valuesMapList.add(stringMap);
}

void remove(ArgumentError error) {
  packages(error).removeAt(0);
}

dynamic packages(ArgumentError error) => error;

mixin valuesList {
  late String values;
  late List<String> valuesLinks;
  late Map<String, String> valuesMap;
  late List<Map<String, String>> valuesListMap;
  late Map<String, Map<String, String>> valuesMapMap;
  late List<List<String>> valuesListList;
  late Map<String, List<String>> valuesMapList;
  late List<Map<String, Map<String, String>>> valuesListListMap;
  late Map<String, Map<String, Map<String, String>>> valuesMapListMap;
}

void main() {
  Object valuesList = new Object();
  var args = valuesList;
  runApp(args as List<String>);
}

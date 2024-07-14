import 'dart:async';

void main(List<String> args) {
  runApp(args);
}

void runApp(List<String> args) {
  runZonedGuarded(() {
    WidgetsFlutterBinding.ensureInitialized();
    runApp(MyApp() as List<String>);
  }, (e, s) {
    print(e);
    print(s);
  });
}

class MyApp {
  late String free;
  late String key;
  late String value;
  late String binding;
  late String community;
  late String server;
  late String port;
  late String username;
  late String password;
  late String database;
  late String table;
  late String column;
  late String homepage;
  late String cloudservices;
  late String cloudservers;
  late String clouds;
  late String cookies;
  late String network;
  late String language;
  late String country;
  late String timezone;
  late String languagecode;
  late String netbeans;
  late String java;
  late String javahome;
  late String javaversion;
  late String javavendor;
  late String Elisp;
  late String Emacs;
  late String EmacsLisp;
  late String EmacsLispHome;
  late String EmacsLispVersion;
  late String EmacsLispPackages;
  late String EmacsToogleDevelopment;
  late String EmacsToogleDevelopmentHome;
  late String EmacsToogleDevelopmentVersion;
  late String EmacsToogleDevelopmentPackages;
  late String EmacsLispPackagesHome;

}

class WidgetsFlutterBinding {
  late String name;

  static instance() => null;

  static void ensureInitialized() {
    if (instance() == null) {
      instance();
    }
  }
}

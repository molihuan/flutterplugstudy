
import 'flutterplugstudy_platform_interface.dart';

class Flutterplugstudy {
  Future<String?> getPlatformVersion() {
    return FlutterplugstudyPlatform.instance.getPlatformVersion();
  }
  Future<String?> passingStr(String p) {
    return FlutterplugstudyPlatform.instance.passingStr(p);
  }
  Future<String?> passingMap(Map<String,String> p) {
    return FlutterplugstudyPlatform.instance.passingMap(p);
  }
}

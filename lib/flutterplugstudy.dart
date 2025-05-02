
import 'flutterplugstudy_platform_interface.dart';

class Flutterplugstudy {
  Future<String?> getPlatformVersion() {
    return FlutterplugstudyPlatform.instance.getPlatformVersion();
  }
}

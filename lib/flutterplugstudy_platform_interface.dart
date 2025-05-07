import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'flutterplugstudy_method_channel.dart';

abstract class FlutterplugstudyPlatform extends PlatformInterface {
  /// Constructs a FlutterplugstudyPlatform.
  FlutterplugstudyPlatform() : super(token: _token);

  static final Object _token = Object();

  static FlutterplugstudyPlatform _instance = MethodChannelFlutterplugstudy();

  /// The default instance of [FlutterplugstudyPlatform] to use.
  ///
  /// Defaults to [MethodChannelFlutterplugstudy].
  static FlutterplugstudyPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [FlutterplugstudyPlatform] when
  /// they register themselves.
  static set instance(FlutterplugstudyPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }

  ///  传递string类型参数
  Future<String?> passingStr(String p) {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }

  Future<String?> passingMap(Map p) {
    throw UnimplementedError('passingMap() has not been implemented.');
  }
}

import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'flutterplugstudy_platform_interface.dart';

/// An implementation of [FlutterplugstudyPlatform] that uses method channels.
class MethodChannelFlutterplugstudy extends FlutterplugstudyPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('flutterplugstudy');

  @override
  Future<String?> getPlatformVersion() async {
    final version = await methodChannel.invokeMethod<String>('getPlatformVersion');
    return version;
  }

  @override
  Future<String?> passingStr(String p) async {
    //传递字符串参数
    final resultStr = await methodChannel.invokeMethod<String>('passingStr',{'paramStr': p});
    return resultStr;
  }

  @override
  Future<String?> passingMap(Map p) async{
    //传递字符串参数
    final resultStr = await methodChannel.invokeMethod<String>('passingMap',p);
    return resultStr;
  }
}

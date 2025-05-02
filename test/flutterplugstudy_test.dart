import 'package:flutter_test/flutter_test.dart';
import 'package:flutterplugstudy/flutterplugstudy.dart';
import 'package:flutterplugstudy/flutterplugstudy_platform_interface.dart';
import 'package:flutterplugstudy/flutterplugstudy_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockFlutterplugstudyPlatform
    with MockPlatformInterfaceMixin
    implements FlutterplugstudyPlatform {

  @override
  Future<String?> getPlatformVersion() => Future.value('42');
}

void main() {
  final FlutterplugstudyPlatform initialPlatform = FlutterplugstudyPlatform.instance;

  test('$MethodChannelFlutterplugstudy is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelFlutterplugstudy>());
  });

  test('getPlatformVersion', () async {
    Flutterplugstudy flutterplugstudyPlugin = Flutterplugstudy();
    MockFlutterplugstudyPlatform fakePlatform = MockFlutterplugstudyPlatform();
    FlutterplugstudyPlatform.instance = fakePlatform;

    expect(await flutterplugstudyPlugin.getPlatformVersion(), '42');
  });
}

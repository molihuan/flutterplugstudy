#ifndef FLUTTER_PLUGIN_FLUTTERPLUGSTUDY_PLUGIN_H_
#define FLUTTER_PLUGIN_FLUTTERPLUGSTUDY_PLUGIN_H_
#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace flutterplugstudy {

class FlutterplugstudyPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  FlutterplugstudyPlugin();

  virtual ~FlutterplugstudyPlugin();

  // Disallow copy and assign.
  FlutterplugstudyPlugin(const FlutterplugstudyPlugin&) = delete;
  FlutterplugstudyPlugin& operator=(const FlutterplugstudyPlugin&) = delete;

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace flutterplugstudy

#endif  // FLUTTER_PLUGIN_FLUTTERPLUGSTUDY_PLUGIN_H_

#include "include/flutterplugstudy/flutterplugstudy_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "flutterplugstudy_plugin.h"

void FlutterplugstudyPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  flutterplugstudy::FlutterplugstudyPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}

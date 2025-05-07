#include "flutterplugstudy_plugin.h"

// This must be included before many other Windows headers.
#include <windows.h>

// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>


extern "C" {
#pragma warning(disable : 4244)
#pragma warning(disable : 4819)
#include <libavcodec/avcodec.h>
}

namespace flutterplugstudy {

// static
void FlutterplugstudyPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {
  auto channel =
      std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
          registrar->messenger(), "flutterplugstudy",
          &flutter::StandardMethodCodec::GetInstance());

  auto plugin = std::make_unique<FlutterplugstudyPlugin>();

  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, std::move(result));
      });

  registrar->AddPlugin(std::move(plugin));
}

FlutterplugstudyPlugin::FlutterplugstudyPlugin() {}

FlutterplugstudyPlugin::~FlutterplugstudyPlugin() {}

void FlutterplugstudyPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
  if (method_call.method_name().compare("getPlatformVersion") == 0) {
    std::ostringstream version_stream;
    version_stream << "Windows ";
    if (IsWindows10OrGreater()) {
      version_stream << "10+";
    } else if (IsWindows8OrGreater()) {
      version_stream << "8";
    } else if (IsWindows7OrGreater()) {
      version_stream << "7";
    }

    result->Success(flutter::EncodableValue(version_stream.str()));
  } else if (method_call.method_name().compare("passingStr") == 0){

      // Get all the arguments passed by the flutter side and convert them to maps
      const auto* args = std::get_if<flutter::EncodableMap>(method_call.arguments());
      if (!args){
          //  没有参数
          result->Error("no param");
          return;
      }

      std::string ret = "windows get params:";
      //  Obtain the parameter whose key is paramStr
      auto param_iter = args->find(flutter::EncodableValue("paramStr"));
      if (param_iter != args->end()){
           std::string param_str = std::get<std::string>(param_iter->second);
           std::cout << param_str << std::endl;
           ret += param_str;
      }
      std::cout << avcodec_configuration() << std::endl;

      result->Success(ret);
  }else if (method_call.method_name().compare("passingMap") == 0){

      // Get all the arguments passed by the flutter side and convert them to maps
      const auto* args = std::get_if<flutter::EncodableMap>(method_call.arguments());
      if (!args){
          //  no param
          result->Error("no param");
          return;
      }

      std::string ret = "windows get params:";

      for (auto iter = args->begin(); iter != args->end(); iter++){
          std::string key = std::get<std::string>(iter->first);
          std::string value = std::get<std::string>(iter->second);
          std::cout << key << ":" << value << std::endl;
          ret += key + ":" + value + " ";
      }

      result->Success(ret);
  }else {
    result->NotImplemented();
  }
}

}  // namespace flutterplugstudy

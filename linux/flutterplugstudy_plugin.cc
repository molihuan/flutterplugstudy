#include "include/flutterplugstudy/flutterplugstudy_plugin.h"

#include <flutter_linux/flutter_linux.h>
#include <gtk/gtk.h>
#include <sys/utsname.h>

#include <cstring>

#include "flutterplugstudy_plugin_private.h"

#define FLUTTERPLUGSTUDY_PLUGIN(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), flutterplugstudy_plugin_get_type(), \
                              FlutterplugstudyPlugin))

struct _FlutterplugstudyPlugin {
  GObject parent_instance;
};

G_DEFINE_TYPE(FlutterplugstudyPlugin, flutterplugstudy_plugin, g_object_get_type())

// Called when a method call is received from Flutter.
static void flutterplugstudy_plugin_handle_method_call(
    FlutterplugstudyPlugin* self,
    FlMethodCall* method_call) {
  g_autoptr(FlMethodResponse) response = nullptr;

  const gchar* method = fl_method_call_get_name(method_call);

  if (strcmp(method, "getPlatformVersion") == 0) {
    response = get_platform_version();
  } else {
    response = FL_METHOD_RESPONSE(fl_method_not_implemented_response_new());
  }

  fl_method_call_respond(method_call, response, nullptr);
}

FlMethodResponse* get_platform_version() {
  struct utsname uname_data = {};
  uname(&uname_data);
  g_autofree gchar *version = g_strdup_printf("Linux %s", uname_data.version);
  g_autoptr(FlValue) result = fl_value_new_string(version);
  return FL_METHOD_RESPONSE(fl_method_success_response_new(result));
}

static void flutterplugstudy_plugin_dispose(GObject* object) {
  G_OBJECT_CLASS(flutterplugstudy_plugin_parent_class)->dispose(object);
}

static void flutterplugstudy_plugin_class_init(FlutterplugstudyPluginClass* klass) {
  G_OBJECT_CLASS(klass)->dispose = flutterplugstudy_plugin_dispose;
}

static void flutterplugstudy_plugin_init(FlutterplugstudyPlugin* self) {}

static void method_call_cb(FlMethodChannel* channel, FlMethodCall* method_call,
                           gpointer user_data) {
  FlutterplugstudyPlugin* plugin = FLUTTERPLUGSTUDY_PLUGIN(user_data);
  flutterplugstudy_plugin_handle_method_call(plugin, method_call);
}

void flutterplugstudy_plugin_register_with_registrar(FlPluginRegistrar* registrar) {
  FlutterplugstudyPlugin* plugin = FLUTTERPLUGSTUDY_PLUGIN(
      g_object_new(flutterplugstudy_plugin_get_type(), nullptr));

  g_autoptr(FlStandardMethodCodec) codec = fl_standard_method_codec_new();
  g_autoptr(FlMethodChannel) channel =
      fl_method_channel_new(fl_plugin_registrar_get_messenger(registrar),
                            "flutterplugstudy",
                            FL_METHOD_CODEC(codec));
  fl_method_channel_set_method_call_handler(channel, method_call_cb,
                                            g_object_ref(plugin),
                                            g_object_unref);

  g_object_unref(plugin);
}

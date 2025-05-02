#ifndef FLUTTER_PLUGIN_FLUTTERPLUGSTUDY_PLUGIN_H_
#define FLUTTER_PLUGIN_FLUTTERPLUGSTUDY_PLUGIN_H_

#include <flutter_linux/flutter_linux.h>

G_BEGIN_DECLS

#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __attribute__((visibility("default")))
#else
#define FLUTTER_PLUGIN_EXPORT
#endif

typedef struct _FlutterplugstudyPlugin FlutterplugstudyPlugin;
typedef struct {
  GObjectClass parent_class;
} FlutterplugstudyPluginClass;

FLUTTER_PLUGIN_EXPORT GType flutterplugstudy_plugin_get_type();

FLUTTER_PLUGIN_EXPORT void flutterplugstudy_plugin_register_with_registrar(
    FlPluginRegistrar* registrar);

G_END_DECLS

#endif  // FLUTTER_PLUGIN_FLUTTERPLUGSTUDY_PLUGIN_H_

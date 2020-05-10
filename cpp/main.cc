#include <napi.h>

// Screen
#include "./screen/getAllScreens/getAllScreensExports.hh"
#include "./screen/getScreenAtPoint/getScreenAtPointExports.hh"

// Mouse
#include "./mouse/getMousePosition/getMousePositionExports.hh"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {

  // Screen
  exports.Set(
    Napi::String::New(env, "getAllScreens"),
    Napi::Function::New(env, getAllScreensCallback)
  );
  exports.Set(
    Napi::String::New(env, "getScreenAtPoint"),
    Napi::Function::New(env, getScreenAtPointCallback)
  );

  // Mouse
  exports.Set(
    Napi::String::New(env, "getMousePosition"),
    Napi::Function::New(env, getMousePositionCallback)
  );

  return exports;
}

NODE_API_MODULE(addon, InitAll);

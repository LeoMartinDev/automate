// Screen imports
#include "./screen/getAllScreens/getAllScreensExports.hh"
#include "./screen/getScreenAtPoint/getScreenAtPointExports.hh"

// Mouse imports
#include "./mouse/getMousePosition/getMousePositionExports.hh"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  // Screen exports
  exports.Set(
    Napi::String::New(env, "getAllScreens"),
    Napi::Function::New(env, getAllScreensCallback)
  );
  exports.Set(
    Napi::String::New(env, "getScreenAtPoint"),
    Napi::Function::New(env, getScreenAtPointCallback)
  );

  // Mouse exports
  exports.Set(
    Napi::String::New(env, "getMousePosition"),
    Napi::Function::New(env, getMousePositionCallback)
  );

  return exports;
}

NODE_API_MODULE(addon, InitAll);

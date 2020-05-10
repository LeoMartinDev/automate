#include "./getMousePositionExports.hh"

Napi::Object serializeMousePosition(Napi::Env env, AppPoint *position) {
  Napi::Object mousePosition = Napi::Object::New(env);

  mousePosition.Set("x", position->x);
  mousePosition.Set("y", position->y);

  return mousePosition;
}

void getMousePositionCallback(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Invalid number of arguments!").ThrowAsJavaScriptException();
    return;
  }

  if (!info[0].IsFunction()) {
    Napi::TypeError::New(env, "Argument 'callback' must be of type 'function'!").ThrowAsJavaScriptException();
    return;
  }

  Napi::Function callback = info[0].As<Napi::Function>();
  GetMousePositionWorker *worker = new GetMousePositionWorker(callback);

  worker->Queue();
}

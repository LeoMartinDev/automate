#include "./getScreenAtPointExports.hh"

void getScreenAtPointCallback(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  if (info.Length() < 3) {
    Napi::TypeError::New(env, "Invalid number of arguments!").ThrowAsJavaScriptException();
    return;
  }

  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Argument 'x' must be of type 'number'!").ThrowAsJavaScriptException();
    return;
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Argument 'y' must be of type 'number'!").ThrowAsJavaScriptException();
    return;
  }

  if (!info[2].IsFunction()) {
    Napi::TypeError::New(env, "Argument 'callback' must be of type 'function'!").ThrowAsJavaScriptException();
    return;
  }

  Napi::Function callback = info[2].As<Napi::Function>();
  AppPoint *point = AppPoint::fromNApiNumber(info[0].As<Napi::Number>(), info[1].As<Napi::Number>());
  GetScreenAtPointWorker *worker = new GetScreenAtPointWorker(callback, point);

  worker->Queue();
}

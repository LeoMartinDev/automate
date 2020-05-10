#include "./getAllScreensExports.hh"

void getAllScreensCallback(const Napi::CallbackInfo &info) {
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
  GetAllScreensWorker *worker = new GetAllScreensWorker(callback);

  worker->Queue();
}
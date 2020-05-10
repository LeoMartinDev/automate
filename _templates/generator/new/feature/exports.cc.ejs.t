---
to: cpp/<%= type %>/<%= feature %>Exports.cc
---
<%
  workerName = h.changeCase.pascal(feature) + 'Worker';
-%>
#include "./<%= feature %>Exports.hh"

void <%= feature %>Callback(const Napi::CallbackInfo &info) {
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
  <%= workerName %> *worker = new <%= workerName %>(callback);

  worker->Queue();
}

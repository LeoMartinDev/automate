---
to: cpp/<%= type %>/<%= feature %>/<%= h.changeCase.pascal(feature) %>Worker.cc
---
<%
  workerName = h.changeCase.pascal(feature) + 'Worker';
-%>
#include "./<%= workerName %>.hh"

<%= workerName %>::<%= workerName %>(Napi::Function &callback)
  : AsyncWorker(callback) {}

<%= workerName %>::~<%= workerName %>() {}

void <%= workerName %>::Execute() {

}

void <%= workerName %>::OnOK() {
  Napi::HandleScope scope(Env());
  Napi::Array returnValue;

  Callback().Call({
    Env().Null(),
    returnValue,
  });
}

void <%= workerName %>::OnError(const Napi::Error &error) {
  Napi::HandleScope scope(Env());

  Callback().Call({
    error.Value(),
    Env().Null(),
  });
}

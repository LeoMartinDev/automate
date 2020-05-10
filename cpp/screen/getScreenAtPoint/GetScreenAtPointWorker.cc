#include "./GetScreenAtPointWorker.hh"

GetScreenAtPointWorker::GetScreenAtPointWorker(Napi::Function &callback, AppPoint *point)
  : AsyncWorker(callback), point(point) {}

GetScreenAtPointWorker::~GetScreenAtPointWorker() {}

void GetScreenAtPointWorker::Execute() {
  this->screen = getScreenAtPoint(this->point);
}

void GetScreenAtPointWorker::OnOK() {
  Napi::HandleScope scope(Env());
  Napi::Object returnValue = this->screen->serialize(Env());

  Callback().Call({
    Env().Null(),
    returnValue,
  });
}

void GetScreenAtPointWorker::OnError(const Napi::Error &error) {
  Napi::HandleScope scope(Env());

  Callback().Call({
    error.Value(),
    Env().Null(),
  });
}

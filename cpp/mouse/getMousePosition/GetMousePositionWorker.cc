#include "./GetMousePositionWorker.hh"

GetMousePositionWorker::GetMousePositionWorker(Napi::Function &callback)
  : AsyncWorker(callback) {}

GetMousePositionWorker::~GetMousePositionWorker() {}

void GetMousePositionWorker::Execute() {
  this->mousePosition = getMousePosition();
  this->mouseDisplay = getScreenAtPoint(this->mousePosition);
}

void GetMousePositionWorker::OnOK() {
  Napi::HandleScope scope(Env());
  Napi::Object returnValue = serializeMousePosition(Env(), this->mousePosition);

  if (this->mouseDisplay != NULL) {
    returnValue.Set("display", this->mouseDisplay->serialize(Env()));
  }

  Callback().Call({
    Env().Null(),
    returnValue,
  });
}

void GetMousePositionWorker::OnError(const Napi::Error &error) {
  Napi::HandleScope scope(Env());

  Callback().Call({
    error.Value(),
    Env().Null(),
  });
}

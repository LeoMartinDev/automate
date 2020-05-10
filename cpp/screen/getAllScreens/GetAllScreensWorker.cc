#include "./GetAllScreensWorker.hh"

GetAllScreensWorker::GetAllScreensWorker(Napi::Function &callback)
  : AsyncWorker(callback) {}

GetAllScreensWorker::~GetAllScreensWorker() {}

void GetAllScreensWorker::Execute() {
  this->screens = getAllScreens();
}

void GetAllScreensWorker::OnOK() {
  Napi::HandleScope scope(Env());
  Napi::Array returnValue = Napi::Array::New(Env(), this->screens.size());

  for(std::vector<int>::size_type i = 0; i != this->screens.size(); i++) {
    returnValue[i] = this->screens[i]->serialize(Env());
  }

  Callback().Call({
    Env().Null(),
    returnValue,
  });
}

void GetAllScreensWorker::OnError(const Napi::Error &error) {
  Napi::HandleScope scope(Env());

  Callback().Call({
    error.Value(),
    Env().Null(),
  });
}

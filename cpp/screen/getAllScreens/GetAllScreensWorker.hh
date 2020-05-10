#if !defined(GET_ALL_SCREENS_WORKER_HH)
#define GET_ALL_SCREENS_WORKER_HH

#include <napi.h>
#include <array>

#include "../../screen/Screen.hh"
#include "./getAllScreensFunctions.hh"

class GetAllScreensWorker : public Napi::AsyncWorker {
  public:
    GetAllScreensWorker(Napi::Function &callback);
    ~GetAllScreensWorker();

  protected:
    void Execute();
    void OnOK();
    void OnError(const Napi::Error &error);

  private:
    std::vector<Screen *> screens;
};

#endif // GET_ALL_SCREENS_WORKER_HH

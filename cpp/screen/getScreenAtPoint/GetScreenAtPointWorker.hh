#if !defined(GET_SCREEN_AT_POINT_WORKER_HH)
#define GET_SCREEN_AT_POINT_WORKER_HH

#include <napi.h>

#include "./getScreenAtPointFunctions.hh"
#include "../Screen.hh"
#include "../../shared/AppPoint/AppPoint.hh"

class GetScreenAtPointWorker : public Napi::AsyncWorker {
  public:
    GetScreenAtPointWorker(Napi::Function &callback, AppPoint *point);
    ~GetScreenAtPointWorker();

  protected:
    void Execute();
    void OnOK();
    void OnError(const Napi::Error &error);

  private:
    AppPoint *point;
    Screen *screen;
};

#endif // GET_SCREEN_AT_POINT_WORKER_HH

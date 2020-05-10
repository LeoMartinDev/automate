#if !defined(GET_MOUSE_POSITION_WORKER_HH)
#define GET_MOUSE_POSITION_WORKER_HH

#include <napi.h>

#include "./getMousePositionFunctions.hh"
#include "../../screen/getScreenAtPoint/getScreenAtPointFunctions.hh"
#include "../../screen/Screen.hh"

class GetMousePositionWorker : public Napi::AsyncWorker {
  public:
    GetMousePositionWorker(Napi::Function &callback);
    ~GetMousePositionWorker();

  protected:
    void Execute();
    void OnOK();
    void OnError(const Napi::Error &error);

  private:
    AppPoint *mousePosition;
    Screen *mouseDisplay;
};

#endif // GET_MOUSE_POSITION_WORKER_HH

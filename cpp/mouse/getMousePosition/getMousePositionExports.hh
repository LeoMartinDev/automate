#if !defined(GET_MOUSE_POSITION_HH)
#define GET_MOUSE_POSITION_HH

#include <napi.h>
#include <functional>

#include "./GetMousePositionWorker.hh"

void getMousePositionCallback(const Napi::CallbackInfo &info);

#endif // GET_MOUSE_POSITION_HH

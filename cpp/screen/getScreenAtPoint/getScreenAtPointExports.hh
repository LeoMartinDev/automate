#if !defined(GET_SCREEN_AT_POINT_EXPORTS_HH)
#define GET_SCREEN_AT_POINT_EXPORTS_HH

#include <napi.h>

#include "./GetScreenAtPointWorker.hh"

void getScreenAtPointCallback(const Napi::CallbackInfo &info);

#endif // GET_SCREEN_AT_POINT_EXPORTS_HH

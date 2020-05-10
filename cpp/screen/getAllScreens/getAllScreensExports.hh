#if !defined(GET_ALL_SCREENS_EXPORT_HH)
#define GET_ALL_SCREENS_EXPORT_HH

#include <napi.h>

#include "./GetAllScreensWorker.hh"

void getAllScreensCallback(const Napi::CallbackInfo &info);

#endif // GET_ALL_SCREENS_EXPORT_HH

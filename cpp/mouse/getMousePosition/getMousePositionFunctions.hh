#if !defined(GET_MOUSE_POSITION_FUNCTIONS_HH)
#define GET_MOUSE_POSITION_FUNCTIONS_HH

#include <napi.h>
#include <ApplicationServices/ApplicationServices.h>
#include <CoreGraphics/CGDisplayConfiguration.h>

#include "../../shared/AppPoint/AppPoint.hh"

Napi::Object serializeMousePosition(Napi::Env env, AppPoint *point);

AppPoint *getMousePosition();

#endif // GET_MOUSE_POSITION_FUNCTIONS_HH

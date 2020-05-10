#if !defined(GET_SCREEN_AT_POINT_FUNCTIONS_HH)
#define GET_SCREEN_AT_POINT_FUNCTIONS_HH

#include <napi.h>

#include "../Screen.hh"

Screen *getScreenAtPoint(AppPoint *point);

#endif // GET_SCREEN_AT_POINT_FUNCTIONS_HH

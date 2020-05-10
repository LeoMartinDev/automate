#if !defined(GET_ALL_SCREENS_FUNCTIONS_HH)
#define GET_ALL_SCREENS_FUNCTIONS_HH

#include <napi.h>
#include <array>
#include <CoreGraphics/CGDisplayConfiguration.h>

#include "../Screen.hh"

std::vector<Screen *> getAllScreens();

#endif // GET_ALL_SCREENS_FUNCTIONS_HH

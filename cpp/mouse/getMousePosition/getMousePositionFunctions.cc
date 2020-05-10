#include "./getMousePositionFunctions.hh"

AppPoint *getMousePosition() {
  CGEventRef event = CGEventCreate(NULL);
  CGPoint cursor = CGEventGetLocation(event);
  CFRelease(event);

  AppPoint *point = AppPoint::fromCGPoint(cursor);

  return point;
}

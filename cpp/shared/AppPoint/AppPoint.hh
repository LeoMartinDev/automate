#if !defined(APP_POINT_HH)
#define APP_POINT_HH

#include <napi.h>
#include <CoreGraphics/CGDisplayConfiguration.h>

class AppPoint {
  public:
    AppPoint(float x, float y);
    ~AppPoint();

  static AppPoint *fromCGPoint(CGPoint point);
  static AppPoint *fromNApiNumber(Napi::Number fromX, Napi::Number fromY);

  float x;
  float y;
};

#endif // APP_POINT_HH

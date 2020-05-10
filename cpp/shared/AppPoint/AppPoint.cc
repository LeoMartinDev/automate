#include "./AppPoint.hh"

AppPoint::AppPoint(float x, float y): x(x), y(y) {}

AppPoint::~AppPoint() {}

AppPoint* AppPoint::fromCGPoint(CGPoint point) {
  return new AppPoint(point.x, point.y);
}

AppPoint* AppPoint::fromNApiNumber(Napi::Number fromX, Napi::Number fromY) {
  float x = fromX.FloatValue();
  float y = fromY.FloatValue();

  return new AppPoint(x, y);
}

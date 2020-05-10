#include "./getScreenAtPointFunctions.hh"

Screen *getScreenAtPoint(AppPoint *appPoint) {
  CGDirectDisplayID displayIds[MAX_DISPLAYS];
  uint32_t matchingDisplays;
  CGPoint point = {
    .x = appPoint->x,
    .y = appPoint->y,
  };

  CGGetDisplaysWithPoint(point, MAX_DISPLAYS, displayIds, &matchingDisplays);

  if (displayIds[0] < 0) {
    return NULL;
  }
  return new Screen(displayIds[0]);
}

#include "./getAllScreensFunctions.hh"

std::vector<Screen *> getAllScreens() {
  CGDirectDisplayID displayIds[MAX_DISPLAYS];
  uint32_t numberOfDisplays;

  CGGetActiveDisplayList(MAX_DISPLAYS, displayIds, &numberOfDisplays);

  std::vector<Screen *> displays;

  for (uint32_t i = 0; i < numberOfDisplays; i++) {
    displays.push_back(new Screen(displayIds[i]));
  }

  return displays;
}
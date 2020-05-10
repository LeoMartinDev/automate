#include "./Screen.hh"

Screen::Screen(uint32_t displayId) {
  this->displayId = displayId;
  this->height = CGDisplayPixelsHigh(displayId);
  this->width = CGDisplayPixelsWide(displayId);
  this->isBuiltIn = CGDisplayIsBuiltin(displayId);
}

Screen::~Screen() {}

Napi::Object Screen::serialize(Napi::Env env) {
  Napi::Object display = Napi::Object::New(env);

  display.Set("height", this->height);
  display.Set("width", this->width);
  display.Set("isBuiltIn", this->isBuiltIn);
  display.Set("id", this->displayId);

  return display;
}

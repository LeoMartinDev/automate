#if !defined(DISPLAY_HH)
#define DISPLAY_HH

#include <napi.h>
#include <ApplicationServices/ApplicationServices.h>

#include "../mouse/getMousePosition/getMousePositionFunctions.hh"
#include "../shared/Serializable.hh"

#define MAX_DISPLAYS 32

class Screen : public Serializable<Napi::Object> {
  public:
    Screen(uint32_t displayId);
    ~Screen();

    Napi::Object serialize(Napi::Env env);

    uint32_t displayId;
    uint32_t height;
    uint32_t width;
    bool isBuiltIn;
};

#endif // DISPLAY_HH

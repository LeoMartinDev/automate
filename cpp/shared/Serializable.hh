#include <napi.h>

template<typename T>
class Serializable {
  public:
    virtual T serialize(Napi::Env env) = 0;
};

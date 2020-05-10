---
to: cpp/<%= type %>/<%= feature %>/<%= feature %>Exports.hh
---
<%
  identifierToken = h.inflection.underscore(feature);
  identifierToken = identifierToken.toUpperCase() + '_EXPORTS_HH';
-%>
#if !defined(<%= identifierToken %>)
#define <%= identifierToken %>

#include <napi.h>

#include "./MoveMouseWorker.hh"

void <%= feature %>Callback(const Napi::CallbackInfo &info);

#endif // <%= identifierToken %>

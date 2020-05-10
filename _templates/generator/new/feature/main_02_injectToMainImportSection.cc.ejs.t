---
to: cpp/main.cc
inject: true
after: // <%= h.inflection.capitalize(type) %> imports
skip_if: <%= feature %>Exports.hh
---
#include "./<%= type %>/<%= feature %>/<%= feature %>Exports.hh"
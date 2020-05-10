---
to: cpp/main.cc
inject: true
after: // <%= h.inflection.capitalize(type) %> exports
skip_if: Napi::String::New\(env, "<%= feature %>"\)
---
<%
  sectionName = h.inflection.capitalize(type) + ' exports';
-%>
  exports.Set(
    Napi::String::New(env, "<%= feature %>"),
    Napi::Function::New(env, <%= feature %>Callback)
  );
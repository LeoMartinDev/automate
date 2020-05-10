---
to: cpp/main.cc
inject: true
after: InitAll
skip_if: <%= h.inflection.capitalize(type) + ' imports' %>
---
<%
  sectionName = h.inflection.capitalize(type) + ' imports';
-%>
// <%= sectionName %>

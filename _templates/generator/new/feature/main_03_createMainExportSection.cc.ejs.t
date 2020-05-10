---
to: cpp/main.cc
inject: true
after: InitAll
skip_if: <%= h.inflection.capitalize(type) + ' exports' %>
---
<%
  sectionName = h.inflection.capitalize(type) + ' exports';
-%>
  // <%= sectionName %>


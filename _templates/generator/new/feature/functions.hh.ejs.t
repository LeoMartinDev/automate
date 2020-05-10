---
to: cpp/<%= type %>/<%= feature %>/<%= feature %>Functions.hh
---
<%
  identifierToken = h.inflection.underscore(feature);
  identifierToken = identifierToken.toUpperCase() + '_FUNCTIONS_HH';
-%>
#if !defined(<%= identifierToken %>)
#define <%= identifierToken %>


#endif // <%= identifierToken %>

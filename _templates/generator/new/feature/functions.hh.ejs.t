---
to: cpp/<%= type %>/<%= feature %>Functions.hh
---
<%
  identifierToken = h.inflection.underscore(feature);
  identifierToken = identifierToken.toUpperCase() + '_FUNCTIONS_HH';
-%>
#if !defined(<%= identifierToken %>)
#define <%= identifierToken %>


#endif // <%= identifierToken %>

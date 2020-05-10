---
to: cpp/<%= type %>/<%= feature %>/<%= h.changeCase.pascal(feature) %>Worker.hh
---
<%
  identifierToken = h.inflection.underscore(feature);
  identifierToken = identifierToken.toUpperCase() + '_WORKER_HH';
  workerName = h.changeCase.pascal(feature) + 'Worker';
-%>
#if !defined(<%= identifierToken %>)
#define <%= identifierToken %>

#include <napi.h>

#include "./<%= feature %>Functions.hh"

class <%= workerName %> : public Napi::AsyncWorker {
  public:
    <%= workerName %>(Napi::Function &callback);
    ~<%= workerName %>();

  protected:
    void Execute();
    void OnOK();
    void OnError(const Napi::Error &error);
};

#endif // <%= identifierToken %>

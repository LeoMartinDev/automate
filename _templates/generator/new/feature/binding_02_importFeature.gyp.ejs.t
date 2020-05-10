---
to: binding.gyp
inject: true
after: "[ ]*#\n[ ]*# <%= type.toUpperCase() %>\n[ ]*#"
skip_if: "[ ]*# <%= feature %>"
---
        # <%= feature %>
        "./cpp/<%= type %>/<%= feature %>/<%= feature %>Functions.cc",
        "./cpp/<%= type %>/<%= feature %>/<%= h.changeCase.pascal(feature) + 'Worker' %>.cc",
        "./cpp/<%= type %>/<%= feature %>/<%= feature %>Exports.cc",
---
to: binding.gyp
inject: true
after: sources
skip_if: "[ ]*#\n[ ]*# <%= type.toUpperCase() %>\n[ ]*#"
---

        #
        # <%= type.toUpperCase() %>
        #


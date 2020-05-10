{
  "targets": [
    {
      "target_name": "automate",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      'cflags+': ['-fvisibility=hidden'],
      'xcode_settings': {
        'GCC_SYMBOLS_PRIVATE_EXTERN': 'YES', # -fvisibility=hidden
      },
      "xcode_settings": {
        "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
        "CLANG_CXX_LIBRARY": "libc++",
        "MACOSX_DEPLOYMENT_TARGET": "10.7",
      },
      "sources": [
        #
        # SHARED
        #
        "./cpp/shared/AppPoint/AppPoint.cc",

        #
        # SCREEN
        #
        "./cpp/screen/Screen.cc",
        # getAllScreens
        "./cpp/screen/getAllScreens/getAllScreensFunctions.cc",
        "./cpp/screen/getAllScreens/GetAllScreensWorker.cc",
        "./cpp/screen/getAllScreens/getAllScreensExports.cc",
        # getScreenAtPoint
        "./cpp/screen/getScreenAtPoint/getScreenAtPointFunctions.cc",
        "./cpp/screen/getScreenAtPoint/GetScreenAtPointWorker.cc",
        "./cpp/screen/getScreenAtPoint/getScreenAtPointExports.cc",

        #
        # MOUSE
        #
        "./cpp/mouse/getMousePosition/getMousePositionFunctions.cc",
        "./cpp/mouse/getMousePosition/GetMousePositionWorker.cc",
        "./cpp/mouse/getMousePosition/getMousePositionExports.cc",

        "./cpp/main.cc"
      ],
      'include_dirs': [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'libraries': [],
      'dependencies': [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      "link_settings": {
        "libraries": [
          "-framework ApplicationServices",
        ]
      },
    },
  ],
}
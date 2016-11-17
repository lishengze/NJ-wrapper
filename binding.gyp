{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "addon.cpp","ftdcsysuserapi-wrapper.cpp", "sysuserspi.cpp","v8-transform-data.cpp","v8-transform-func.cpp",
                   "id-func.cpp", "tool-function.cpp","charset-convert-windows.cpp","CCrypto.h","CDes.cpp" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        ".",
      ],
      "libraries": [
         "-lC:\NodejsWrapper\windows-simple-new/sysuserapi.lib"
      ]
    }
  ]
}

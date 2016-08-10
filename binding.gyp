{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "addon.cpp","ftdcsysuserapi-wrapper.cpp", "sysuserspi.cpp","v8-transform-data.cpp","v8-transform-func.cpp", "id-func.cpp", "tool-function.cpp","charset-convert-linux.cpp","CCrypto.h","CDes.cpp" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        ".",
      ],
      "libraries": [
         # "-lC:\Users\li.shengze\github\Nodejs\socket.io-warpper\suaw-async-queue-g/sysuserapi.lib",
         "-lsysuserapi",
      ]
    }
  ]
}

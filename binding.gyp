{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "addon.cpp","ftdcsysuserapi-wrapper.cpp", "sysuserspi.cpp","spi-transform.cpp", "CCrypto.h","CDes.cpp" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        ".",
      ],
      "libraries": [
          "-lC:\Users\li.shengze\github\Nodejs\socket.io-warpper\suaw-async-queue-e/sysuserapi.lib",
         # "-lsysuserapi.lib",
      ]
    }
  ]
}

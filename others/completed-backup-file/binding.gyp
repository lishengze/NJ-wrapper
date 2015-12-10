{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "addon.cpp","FtdcSysUserApi_Wrapper.cpp", "SysUserSpi.cpp","SpiCFunc.cpp", "CCrypto.h","CDes.cpp" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        ".",
      ],
      "libraries": [
          "-lC:/Users/li.shengze/github/Nodejs/Addons/SysUserApiWrapper_Test_Sync/sysuserapi.lib",
      ]
    }
  ]
}

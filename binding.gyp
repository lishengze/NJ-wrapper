{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "addon.cc", "FtdcSysUserApi_Wrapper.cc","SysUserSpi.cc","SpiCFunc.cc", "CCrypto.h","CDes.cpp" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        ".",
      ],
      "libraries": [
          "-lC:/Users/li.xiankui/mywork/SysUserApiWrapper/sysuserapi.lib",
      ]
    }
  ]
}

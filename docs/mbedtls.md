#### 使用 MbedTLS 替代 OpenSSL
=====

1 [构建 mbedtls](https://github.com/ARMmbed/mbedtls)

 - 1.1 克隆 mbedtls 仓库并切换到指定版本：  
   `git clone https://github.com/ARMmbed/mbedtls.git -b mbedtls-2.24.0`
 - 1.2 在多线程环境中使用 Arm Mbed TLS，在 `config.h` 中启用 `MBEDTLS_THREADING_C` 和 `MBEDTLS_THREADING_PTHREAD`，[更多信息](https://tls.mbed.org/kb/development/thread-safety-and-multi-threading)
 - 1.3 构建并安装：  
   `make SHARED=1 && make install`

2 构建 civetweb

 - 使用 MbedTLS 构建：  
   `make build WITH_MBEDTLS=1`

3 运行 civetweb
 - 设置动态库路径：  
   `export LD_LIBRARY_PATH=/usr/local/lib/:$LD_LIBRARY_PATH`
 - 启动 civetweb，指定监听端口和 SSL 证书：  
   `./civetweb -listening_ports 8443s -ssl_certificate resources/cert/server.pem -document_root ./test/htmldir/`
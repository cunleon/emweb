# 构建 CivetWeb
=========

本指南涵盖了独立 Web 服务器的构建说明。有关扩展现有 C 或 C++ 应用程序的信息，请参阅 [Embedding.md](https://github.com/civetweb/civetweb/blob/master/docs/Embedding.md)。源代码文件的简要概述也可以在 [Embedding.md](https://github.com/civetweb/civetweb/blob/master/docs/Embedding.md) 中找到。

#### 如何获取源代码？

最新的开发版本可以在以下地址找到：  
https://github.com/civetweb/civetweb

经过测试和发布的版本可以在以下地址找到：  
https://github.com/civetweb/civetweb/releases


在 Windows 上构建
---------

#### 使用 Visual Studio

在 Visual Studio 中打开 *VS/civetweb.sln*。  
要包含 SSL 支持，您可能需要为加密支持添加额外的库。您可以使用 yaSSL，但它使用 GPL 许可证或商业许可证。有关更多信息，请参阅 [yaSSL.md](https://github.com/civetweb/civetweb/blob/master/docs/yaSSL.md)。  
或者，您可以使用 OpenSSL。有关更多信息，请参阅 [OpenSSL.md](https://github.com/civetweb/civetweb/blob/master/docs/OpenSSL.md)。

#### 使用 MinGW-w64 或 TDM-GCC
在开始菜单中找到并运行“Run terminal”批处理文件。对于 TDM-GCC，此文件名为“MinGW Command Prompt”。  
导航到 civetweb 源代码目录并运行：
```
mingw32-make CC=gcc
```

#### 使用 Qt Creator
打开 Qt 文件夹中的 Qt Designer 项目。

#### 使用 CMake
除了 `third_party` 文件夹中的组件（例如 Lua 和 Duktape），CivetWeb 也可以使用 CMake 构建。CMake 可用于所有支持的操作系统。


在 Linux、BSD 和 OSX 上构建
---------

## 使用 Make

```
make help
```
获取所有支持的 make 选项列表。

```
make build
make WITH_ALL=1
```
编译代码。  
使用选项 "WITH_ALL=1" 启用所有可选功能。

```
make install
```
在系统上安装，仅适用于 Linux。

```
make lib WITH_IPV6=1
make clean slib WITH_LUA=1 WITH_WEBSOCKET=1
```
构建静态和共享库。  
额外的 make 选项配置库的方式与配置应用程序相同。

*slib* 选项应在单独的干净构建中完成，因为需要位置无关代码（PIC）。在构建静态库或服务器后尝试运行它会导致链接错误。

```
make clean
```
清理构建过程中生成的文件。


## 设置构建选项

可以在命令行中使用 make 命令设置构建选项，例如：
```
make build WITH_LUA=1
```


| Make 选项                | 描述                                       |
| --------------------------- | ------------------------------------------------- |
| `WITH_LUA=1`                | 构建支持 Lua 的版本                            |
| `WITH_DUKTAPE=1`            | 构建支持服务器端 JavaScript 的版本         |
| `WITH_IPV6=1`               | 支持 IPv6                                 |
| `WITH_WEBSOCKET=1`          | 构建支持 WebSocket 的版本                     |
| `WITH_X_DOM_SOCKET=1`       | 构建支持 Unix 域套接字的版本       |
| `WITH_SERVER_STATS=1`       | 构建支持服务器统计的版本          |
| `WITH_EXPERIMENTAL=1`       | 包含实验性功能（取决于版本） |
| `WITH_ALL=1`                | 包含上述所有功能                 |
| `WITH_DEBUG=1`              | 构建支持 GDB 调试的版本                      |
| `WITH_CPP=1`                | 构建包含 C++ 类的库                  |
| `CONFIG_FILE=file`          | 使用 'file' 作为配置文件                     |
| `CONFIG_FILE2=file`         | 使用 'file' 作为备用配置文件              |
| `HTMLDIR=/path`             | 安装初始网页的路径                |
| `DOCUMENT_ROOT=/path`       | 默认文档根目录                     |
| `PORTS=8080`                | 安装时覆盖监听端口          |
| `SSL_LIB=libssl.so.0`       | 使用版本化的 SSL 库                         |
| `CRYPTO_LIB=libcrypto.so.0` | 使用系统版本化的 CRYPTO 库                   |
| `PREFIX=/usr/local`         | 设置安装目录                        |
| `COPT='-DNO_SSL'`           | 插入编译标志的方法                    |

请注意，用于 *make* 的 WITH_* 选项与源代码中的预处理器定义不完全相同——通常使用 USE_*。


## 更改 PREFIX

要更改目标安装路径，请将 `PREFIX` 选项传递给 `make install` 命令（而不是 `make build`）。示例用法：

```
$ make build
$ make -n install PREFIX=/opt/civetweb
```
注意：`-n` 对应于 `--dry-run` 选项（它不会进行任何更改）：您可以查看 `make install` 将安装的位置。上述命令的示例输出：

```
$ make -n install PREFIX=/opt/civetweb
install -d -m 755  "/opt/civetweb/share/doc/civetweb"
install -m 644 resources/itworks.html /opt/civetweb/share/doc/civetweb/index.html
install -m 644 resources/civetweb_64x64.png /opt/civetweb/share/doc/civetweb/
install -d -m 755  "/opt/civetweb/etc"
install -m 644 resources/civetweb.conf  "/opt/civetweb/etc/"
sed -i 's#^document_root.*$#document_root /opt/civetweb/share/doc/civetweb#' "/opt/civetweb/etc/civetweb.conf"
sed -i 's#^listening_ports.*$#listening_ports 8080#' "/opt/civetweb/etc/civetweb.conf"
install -d -m 755  "/opt/civetweb/share/doc/civetweb"
install -m 644 *.md "/opt/civetweb/share/doc/civetweb"
install -d -m 755 "/opt/civetweb/bin"
install -m 755 civetweb "/opt/civetweb/bin/"
```

如果输出看起来不错：只需删除 `-n` 选项即可在系统上实际安装软件。


## 设置编译标志

可以使用 *COPT* make 选项设置编译标志，例如：
```
make build COPT="-DNDEBUG -DNO_CGI"
```

| 编译标志                | 描述                                                         |
| ---------------------------- | ------------------------------------------------------------------- |
| `NDEBUG`                     | 去除所有调试代码                                            |
| `DEBUG`                      | 构建调试版本（非常冗长）                                    |
|                              |                                                                     |
| `NO_ATOMICS`                 | 不使用原子函数，改用锁                                      |
| `NO_CACHING`                 | 禁用缓存功能                                                 |
| `NO_CGI`                     | 禁用 CGI 支持                                                 |
| `NO_FILES`                   | 不从目录提供文件                                             |
| `NO_FILESYSTEMS`             | 完全禁用文件系统使用（需要 NO_FILES）                        |
| `NO_NONCE_CHECK`             | 禁用 HTTP 摘要认证的 nonce 检查                              |
| `NO_RESPONSE_BUFFERING`      | 立即发送所有 mg_response_header_*，而不是缓冲到 mg_response_header_send 调用 |
| `NO_SSL`                     | 禁用 SSL 功能                                                 |
| `NO_SSL_DL`                  | 链接系统 libssl 库                                           |
| `NO_THREAD_NAME`             | 不为 pthread 设置名称                                        |
|                              |                                                                     |
| `USE_ALPN`                   | 启用应用层协议协商（ALPN），HTTP2 必需                       |
| `USE_DUKTAPE`                | 启用服务器端 JavaScript（使用 Duktape 库）                   |
| `USE_HTTP2`                  | 启用 HTTP2 支持（实验性，不建议用于生产环境）                 |
| `USE_IPV6`                   | 启用 IPv6 支持                                                |
| `USE_LUA`                    | 启用 Lua 支持                                                 |
| `USE_SERVER_STATS`           | 启用服务器统计支持                                            |
| `USE_STACK_SIZE`             | 定义堆栈大小，而不是使用系统默认值                            |
| `USE_WEBSOCKET`              | 启用 WebSocket 支持                                           |
| `USE_X_DOM_SOCKET`           | 启用 Unix 域套接字支持                                        |
| `USE_ZLIB`                   | 启用文件即时压缩（使用 zlib）                                 |
|                              |                                                                     |
| `MG_EXPERIMENTAL_INTERFACES` | 包含实验性接口                                                |
| `MG_LEGACY_INTERFACE`        | 包含过时的接口（可能被删除的候选）                            |
|                              |                                                                     |
| `SQLITE_DISABLE_LFS`         | 禁用大文件支持（仅限 Lua）                                    |
| `SSL_ALREADY_INITIALIZED`    | 不初始化 libcrypto                                            |
| `OPENSSL_API_1_0`            | 使用 OpenSSL V1.0.x 接口                                       |
| `OPENSSL_API_1_1`            | 使用 OpenSSL V1.1.x 接口                                       |
| `OPENSSL_API_3_0`            | 使用 OpenSSL V3.0.x 接口                                       |
| `USE_GNUTLS`                 | 使用 GnuTLS（不能与 OPENSSL_API_* 或 USE_MBEDTLS 结合使用）   |
| `USE_MBEDTLS`                | 使用 MbedTLS（不能与 OPENSSL_API_* 或 USE_GNUTLS 结合使用）   |
|                              |                                                                     |
| `BUILD_DATE`                 | 定义字符串以用作构建 ID，而不是使用 __DATE__                 |
|                              |                                                                     |


注意：如果使用 `make`（使用此 [Makefile](https://github.com/civetweb/civetweb/blob/master/Makefile)），您不应使用 `COPT` 传递 `USE_<feature>` 标志，而应使用上面的 `WITH_<feature>` 语法，因为附加功能可能还需要额外的源代码文件。


## 交叉编译

使用 *CC*、*COPT* 和 *TARGET_OS* 作为 make 选项来完全控制构建。  
TARGET_OS 用于确定一些编译细节以及代码功能。  
TARGET_OS 值应为 *resources/Makefile.in-os* 中找到的值之一。

```
make CC=arm-none-linux-gnueabi-gcc COPT="-march=armv7-a  -mfpu=vfp -mfloat-abi=softfp" TARGET_OS=FROG
```

## Cocoa DMG 打包（仅限 OSX）

使用替代的 *Makefile.osx* 进行构建。整个构建必须使用 *Makefile.osx*，因为需要额外的编译和链接选项。此 Makefile 具有与另一个 Makefile 相同的选项，外加一个额外的 *package* 规则。

```
make -f Makefile.osx package
```

使用 Buildroot 构建
---------

[Buildroot](http://buildroot.uclibc.org/) 是一个用于创建交叉编译文件系统的工具。将 Civetweb 包含在 Buildroot 中非常简单，甚至支持各种构建选项。

1. 首先，检查是否已经存在。
   - 在 Buildroot 中，运行 `make menuconfig`。
     - Package Selection for the target --->
     - Networking applications  --->
     - civetweb
2. 如果不存在，只需添加它。
   - 将 Civetweb 的 *contrib/buildroot/* 中的 *Config.in* 和 *civetweb.mk* 复制到 Buildroot 的 *package/civetweb/* 目录中。
   - 在 Buildroot 的 *package/Config.in* 中插入以下行，以便在菜单中找到它。
     > ``` source "package/civetweb/Config.in" ```


在 Android 上构建
---------

这是一个小指南，帮助您在 Android 上运行 civetweb，最初在 HTC Wildfire 上测试。  
注意：您不需要 root 访问权限即可在 Android 上运行 civetweb。

- 从下载页面下载源代码。
- 从 [http://developer.android.com/tools/sdk/ndk/index.html](http://developer.android.com/tools/sdk/ndk/index.html) 下载 Android NDK。
- 运行 `/path-to-ndk/ndk-build -C /path-to-civetweb/resources`  
  这应该会生成 civetweb/lib/armeabi/civetweb。
- 使用 adb 工具（您需要安装 Android SDK），将生成的 civetweb 二进制文件推送到设备上的 `/data/local` 文件夹。
- 在 adb shell 中，导航到 `/data/local` 并执行 `./civetweb`。
- 要测试服务器是否正常运行，请在 Web 浏览器中访问 `http://127.0.0.1:8080`，您应该会看到 `Index of /` 页面。


注意事项：

- `jni` 代表 Java 本地接口。如果您想了解如何在 Android Java 应用程序中与 civetweb 的本地 C 函数交互，请阅读有关 Android NDK 的内容。
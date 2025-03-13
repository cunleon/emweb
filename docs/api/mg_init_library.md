# Civetweb API 参考

### `mg_init_library(feature);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`feature`** | `unsigned` | 一个表示要初始化的功能的位掩码 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `unsigned` | 表示已初始化的功能的值。成功时返回非零值，错误时返回 **0** |

### 说明

`mg_init_library()` 函数应在应用程序中使用任何其他 Civetweb 函数之前调用。它可以多次调用（`mg_init_library` 和 `mg_exit_library` 是引用计数的）。然而，调用者必须确保它不会被并行调用（不能保证它是线程安全的）。

此函数从 1.9 版本开始引入（作为虚拟实现），从 1.10 版本开始生效。为了兼容性，其他函数（如 [`mg_start();`](mg_start.md)）也会初始化所需的特性，但它们不会再进行反初始化，这可能会在库卸载时导致内存泄漏。

可以使用以下参数值：

| 值 | 编译选项 | 功能标志 | 描述 |
| :---: | :---: | :--- | :--- |
| **1** | !NO_FILES | MG_FEATURES_FILES | *支持文件服务*。如果此功能可用，Web 服务器能够直接从目录树中提供文件。 |
| **2** | !NO_SSL | MG_FEATURES_TLS | *支持 HTTPS*。如果此功能可用，Web 服务器可以在客户端与服务器之间的连接中使用加密。支持的协议取决于编译时使用的 SSL 库（SSLv2、SSLv3、TLSv1.0、TLSv1.1 和 TLSv1.2），但实际运行时使用的协议取决于启动服务器时的选项。 |
| **4** | !NO_CGI | MG_FEATURES_CGI | *支持 CGI*。如果此功能可用，Web 服务器可以调用外部 CGI 脚本。 |
| **8** | USE_IPV6 | MG_FEATURES_IPV6 | *支持 IPv6*。CivetWeb 库支持 IPv4 和 IPv6 通信，但 IPv6 支持必须在编译时启用。 |
| **16** | USE_WEBSOCKET | MG_FEATURES_WEBSOCKET | *支持 WebSocket*。如果编译时使用了适当的选项，CivetWeb 库将支持 WebSocket。 |
| **32** | USE_LUA | MG_FEATURES_LUA | *支持 Lua 脚本和 Lua 服务器页面*。如果在编译时启用，CivetWeb 支持通过 Lua 语言进行服务器端脚本编写。Lua 是一种高效的脚本语言，资源占用比 PHP 等语言更少。 |
| **64** | USE_DUKTAPE | MG_FEATURES_SSJS | *支持服务器端 JavaScript*。如果编译时启用了适当的选项，可以使用服务器端 JavaScript 进行动态页面生成。请注意，客户端 JavaScript 的执行始终取决于连接的浏览器是否启用。 |
| **128** | !NO_CACHING | MG_FEATURES_CACHE | *支持缓存*。如果在编译库时未禁用，Web 服务器将支持缓存。 |
| **256** | USE_SERVER_STATS | MG_FEATURES_STATS | *支持服务器统计*。Web 服务器将收集服务器统计信息。 |
| **512** | USE_ZLIB | MG_FEATURES_COMPRESSION | *支持实时压缩*。Web 服务器可能会使用 ZLIB 进行实时数据压缩。 |
| **1024** | USE_HTTP2 | MG_FEATURES_HTTP2 | *支持 HTTP/2 协议*。Web 服务器将通过 HTTPS 接受 HTTP/2 连接。 |
| **2048** | USE_X_DOM_SOCKET | MG_FEATURES_X_DOMAIN_SOCKET | *支持 UNIX 域套接字*。Web 服务器将允许绑定到域套接字，而不仅仅是 TCP 套接字。 |
| **65535** | | MG_FEATURES_ALL | 所有功能标志 |

参数可以通过位或操作组合使用。值大于 65535 是保留的，如果设置了任何未知位，函数的行为是未定义的。

### 参考

* [`mg_check_feature(feature);`](mg_check_feature.md)
* [`mg_exit_library(feature);`](mg_exit_library.md)
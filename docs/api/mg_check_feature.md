# Civetweb API 参考

### `mg_check_feature(feature);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`feature`** | `unsigned` | 表示要检查的功能的值 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `unsigned` | 表示功能是否可用的值。正值表示功能可用，而返回 **0** 表示功能不可用 |

### 说明

`mg_check_feature()` 函数可用于检查应用程序链接到的 CivetWeb 版本是否编译了特定功能。要检查的功能以无符号整数参数提供。如果当前链接的库版本中包含该功能，则返回值 **> 0**，否则返回 **0**。

可以使用以下参数值：

| 值 | 编译选项 | 描述 |
| :---: | :---: | :--- |
| **1** | NO_FILES | *支持文件服务*。如果此功能可用，Web 服务器能够直接从目录树中提供文件。 |
| **2** | NO_SSL | *支持 HTTPS*。如果此功能可用，Web 服务器可以在客户端与服务器之间的连接中使用加密。支持的协议取决于编译时使用的 SSL 库（SSLv2、SSLv3、TLSv1.0、TLSv1.1 和 TLSv1.2），但实际运行时使用的协议取决于启动服务器时的选项。 |
| **4** | NO_CGI | *支持 CGI*。如果此功能可用，Web 服务器可以调用外部 CGI 脚本。 |
| **8** | USE_IPV6 | *支持 IPv6*。CivetWeb 库支持 IPv4 和 IPv6 通信，但 IPv6 支持必须在编译时启用。 |
| **16** | USE_WEBSOCKET | *支持 WebSocket*。如果编译时使用了适当的选项，CivetWeb 库将支持 WebSocket。 |
| **32** | USE_LUA | *支持 Lua 脚本和 Lua 服务器页面*。如果在编译时启用，CivetWeb 支持通过 Lua 语言进行服务器端脚本编写。Lua 是一种高效的脚本语言，资源占用比 PHP 等语言更少。 |
| **64** | USE_DUKTAPE | *支持服务器端 JavaScript*。如果编译时启用了适当的选项，可以使用服务器端 JavaScript 进行动态页面生成。请注意，客户端 JavaScript 的执行始终取决于连接的浏览器是否启用。 |
| **128** | NO_CACHING | *支持缓存*。如果在编译库时未禁用，Web 服务器将支持缓存。 |

**注意**：  
除了上述列出的值之外，其他参数值将导致未定义的结果。虽然 `mg_check_feature()` 函数的参数值实际上是位掩码，但不应假设将两个值通过 OR 操作组合成一个新值时，函数返回的结果会有任何实际意义。

### 参考

* [`mg_get_option();`](mg_get_option.md)
* [~~`mg_get_valid_option_names();`~~](mg_get_valid_option_names.md)
* [`mg_get_valid_options();`](mg_get_valid_options.md)
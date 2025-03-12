# Civetweb API Reference

### `mg_check_feature( feature );`

### Parameters

| Parameter | Type | Description |
| :--- | :--- | :--- |
|**`feature`**|`unsigned`| A value indicating the feature to be checked |

### Return Value

| Type | Description |
| :--- | :--- |
|`unsigned`| A value indicating if a feature is available. A positive value indicates available, while **0** is returned for an unavailable feature |

### Description

可以从应用程序调用函数 'mg_check_feature（）' 来检查应用程序链接到的 civetweb 版本中是否已编译特定功能。要检查的特征以无符号整数参数的形式提供。如果该函数在当前链接的库版本中可用，则返回值 **> 0**。否则，函数 'mg_check_feature（）' 返回值 **0**。

可以使用以下参数值：

|价值 |编译选项 |描述 |
|:---: |:---: |:--- |
|**1** |NO_FILES |*能够提供文件*。如果此功能可用，则 Web 服务器能够直接从目录树提供文件。|
|**2** |NO_SSL |*支持 HTTPS*。如果此功能可用，则 Web 服务器货车将在客户端-服务器连接中使用加密。支持 SSLv2、SSLv3、TLSv1.0、TLSv1.1 和 TLSv1.2 取决于 CivetWeb 编译时使用的 SSL 库，但是在服务器运行时有效使用哪些协议取决于服务器启动时使用的选项。|
|**4** |NO_CGI |*支持 CGI*。如果此功能可用，则 Web 服务器可以调用外部 CGI 脚本。|
|**8** |USE_IPV6 |*支持 IPv6*。CivetWeb 库能够通过 IPv4 和 IPv6 进行通信，但 IPv6 支持仅在编译时启用后才可用。|
|**16** |USE_WEBSOCKET |支持 Web 套接字。如果在 cimpile 期间使用了正确的选项，则 CivetWeb 库中提供了 WebSockets 支持。|
|**32** |USE_LUA |*支持 Lua 脚本和 Lua 服务器页面*。CivetWeb 通过 Lua 语言支持服务器端脚本，如果在编译时启用了该语言。Lua 是一种高效的脚本语言，它比 PHP 占用的资源更少。|
|**64** |USE_DUKTAPE |*支持服务器端 JavaScript*。如果在编译时设置了适当的选项，则可以使用服务器端 JavaScript 生成动态页面。请注意，如果在连接浏览器中启用了客户端 JavaScript 执行，则它始终可用。|
|**128** |NO_CACHING |*支持缓存*。如果在编译库时未禁用缓存，则 Web 服务器将支持缓存。|

除上述值以外的参数值将产生未定义的结果。因此，尽管 'mg_check_feature（）' 函数的参数值实际上是位掩码，但您不应假设在函数返回时，将其中两个值与 OR 组合为新值会得到任何有意义的结果。
### See Also

* [`mg_get_option();`](mg_get_option.md)
* [~~`mg_get_valid_option_names();`~~](mg_get_valid_option_names.md)
* [`mg_get_valid_options();`](mg_get_valid_options.md)

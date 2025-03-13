# Civetweb API Reference

### `mg_download( host, port, use_ssl, error_buffer, error_buffer_size, fmt, ... );`

### Parameters

| Parameter | Type | Description |
| :--- | :--- | :--- |
|**`host`**|`const char *`|The hostname or IP address of the server|
|**`port`**|`int`|The port number on the server|
|**`use_ssl`**|`int`|Use SSL if this value is not equal zero|
|**`error_buffer`**|`char *`|Buffer to store an error message|
|**`error_buffer_size`**|`size_t`|Size of the error message buffer including the terminating NUL|
|**`fmt`**|`const char *`|Format string specifying the remote command to execute|
|**`...`**|*various*|Parameters used in the format string|

### Return Value

| Type | Description |
| :--- | :--- |
|`struct mg_connection *`|A pointer to the connection structure if successful and NULL otherwise|

### Description

mg_download() 函数用于从远程 Web 服务器下载数据。服务器地址可以指定为主机名或 IP 地址，如果需要，可以使用 SSL。如果函数执行成功，将返回一个指向连接结构体的指针。连接必须通过调用 mg_close_connection.md 函数关闭。
格式字符串是 printf() 系列函数中的格式字符串，用于指定远程命令。以下是一个从 Google 获取主页的示例调用：

conn = mg_download("google.com", 80, 0, ebuf, sizeof(ebuf),
                   "%s", "GET / HTTP/1.0\r\nHost: google.com\r\n\r\n");
请注意，尽管 Civetweb 支持 IPv4 和 IPv6 通信，但 IPv6 地址仅在编译时启用时才可用。在运行应用程序时，可以通过使用带有参数 USE_IPV6 的函数 md_check_feature.md 来检查是否编译了 IPv6 支持。

### See Also

* [`mg_check_feature();`](mg_check_feature.md)
* [`mg_close_connection();`](mg_close_connection.md)

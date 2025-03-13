# Civetweb API Reference

### `mg_connect_client( host, port, use_ssl, error_buffer, error_buffer_size );`

### Parameters

| Parameter | Type | Description |
| :--- | :--- | :--- |
|**`host`**|`const char *`|hostname or IP address of the server|
|**`port`**|`int`|The port to connect to on the server|
|**`use_ssl`**|`int`|Connects using SSL of this value is not zero|
|**`error_buffer`**|`char *`|Buffer to store an error message|
|**`error_buffer_size`**|`size_t`|Maximum size of the error buffer including the NUL terminator|

### Return Value

| Type | Description |
| :--- | :--- |
|`struct mg_connection *`||

### Description

mg_connect_client() 函数作为客户端连接到一个 TCP 服务器。该服务器可以是一个 HTTP 服务器，但并非必须如此。当连接成功建立时，函数返回一个指向连接结构体的指针，否则返回 NULL。目标主机可以是 IPv4 或 IPv6，但并非所有 Civetweb 安装都支持 IPv6。具体来说，IPv6 通信功能必须在编译库时启用。在运行时，可以使用函数 mg_check_feature() 并传入参数 USE_IPV6 来检查是否支持 IPv6 通信。
 
### See Also

* [`mg_check_feature();`](mg_check_feature.md)
* [`mg_connect_client_secure();`](mg_connect_client_secure.md)
* [`mg_connect_websocket_client();`](mg_connect_websocket_client.md)

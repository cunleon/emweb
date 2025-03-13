# Civetweb API Reference

### `mg_connect_websocket_client( host, port, use_ssl, error_buffer, error_buffer_size, path, origin, data_func, close_func, user-data);`

### Parameters

| Parameter | Type | Description |
| :--- | :--- | :--- |
|**`host`**|`const char *`|The hostname or IP address of the server|
|**`port`**|`int`|The port on the server|
|**`use_ssl`**|`int`|Use SSL if this parameter is not equal to zero|
|**`error_buffer`**|`char *`|Buffer to store an error message|
|**`error_buffer_size`**|`size_t`|Size of the error message buffer including the NUL terminator|
|**`path`**|`const char *`|The server path to connect to, for example `/app` if you want to connect to `localhost/app`|
|**`origin`**|`const char *`|The value of the `Origin` HTTP header|
|**`data_func`**|`mg_websocket_data_handler`|Callback which is used to process data coming back from the server|
|**`close_func`**|`mg_websocket_close_handler`|Callback which is called when the connection is to be closed|
|**`user_data`**|`void *`|User supplied argument|

### Return Value

| Type | Description |
| :--- | :--- |
|`struct mg_connection *`|A pointer to the connection structure, or NULL if connecting failed|

### Description

mg_connect_websocket_client() 函数作为客户端连接到服务器上的一个 WebSocket。数据和关闭事件通过回调函数进行处理，这些回调函数必须在调用时提供。
Civetweb 支持 IPv4 和 IPv6 通信，但前提是 IPv6 必须在编译时启用。当运行应用程序时，可以通过调用 mg_check_feature() 函数并传入 USE_IPV6 参数来检查是否支持 IPv6 地址。

### See Also

* [`mg_check_feature();`](mg_check_feature.md)
* [`mg_connect_client();`](mg_connect_client.md)
* [`mg_connect_client_secure();`](mg_connect_client_secure.md)

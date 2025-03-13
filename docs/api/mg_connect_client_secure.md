# Civetweb API Reference

### `mg_connect_client_secure( client_options, error_buffer, error_buffer_size );`

### Parameters

| Parameter | Type | Description |
| :--- | :--- | :--- |
|**`client_options`**|`const struct mg_client_options *`|Settings about the server connection|
|**`error_buffer`**|`char *`|Buffer to store an error message|
|**`error_buffer_size`**|`size_t`|Size of the error message buffer including the NUL terminator|

### Return Value

| Type | Description |
| :--- | :--- |
|`struct mg_connection *`||

### Description

mg_connect_client_secure() 函数用于与服务器建立安全连接。连接和服务器的相关信息通过一个结构体传递，错误信息可能会返回到一个本地缓冲区。函数在成功时返回指向 struct mg_connection 结构体的指针，否则返回 NULL。
请注意，Civetweb 支持 IPv6 通信，但这仅在编译时启用了 IPv6 功能时才有效。在运行程序时，可以通过调用函数 mg_check_feature() 并传入 USE_IPV6 参数来检查是否支持 IPv6 通信。

### See Also

* [`struct mg_client_options;`](mg_client_options.md)
* [`mg_check_feature();`](mg_check_feature.md)
* [`mg_connect_client();`](mg_connect_client.md)
* [`mg_connect_websocket_client();`](mg_connect_websocket_client.md)

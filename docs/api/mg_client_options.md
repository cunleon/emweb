# Civetweb API Reference

### `struct mg_client_options;`

### Fields

| Field | Type | Description |
| :--- | :--- | :--- |
|**`host`**|`const char *`|The hostname or IP address to connect to|
|**`port`**|`int`|The port on the server|
|**`client_cert`**|`const char *`|Pointer to client certificate|
|**`server_cert`**|`const char *`|Pointer to a server certificate|

### Description

mgclient_options结构体包含主机和安全信息，用于作为客户端连接到其他主机。这种类型的参数用于调用函数mg_connect_client_secure()。请注意，只有在编译时启用了IPv6支持，才允许使用IPv6地址。您可以在运行应用程序时使用mg_check_feature()函数，传入参数USE_IPV6来检查是否支持IPv6。

### See Also

* [`mg_check_feature();`](mg_check_feature.md)
* [`mg_connect_client_secure();`](mg_connect_client_secure.md)

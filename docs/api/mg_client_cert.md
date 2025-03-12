# Civetweb API Reference

### `struct mg_client_cert;`

### Fields

| Field | Type | Description |
| :--- | :--- | :--- |
|**`subject`**|`const char *`| 证书的使用者 |
|**`issuer`**|`const char *`| 证书的颁发者 |
|**`serial`**|`const char *`| 证书的序列号 |
|**`finger`**|`const char *`| 证书的指纹 |


### Description

结构 'client_cert' 用作 ['mg_request_info']（mg_request_info.md） 结构中的子结构，以存储可选客户端提供的证书的信息。

### See Also

* [`struct mg_request_info;`](mg_request_info.md)
* [`mg_get_request_info();`](mg_get_request_info.md)

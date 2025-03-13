# Civetweb API 参考

### `struct mg_client_cert;`

### 字段

| 字段 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`subject`** | `const char *` | 证书的主题（Subject） |
| **`issuer`** | `const char *` | 证书的颁发者（Issuer） |
| **`serial`** | `const char *` | 证书的序列号（Serial Number） |
| **`finger`** | `const char *` | 证书的指纹（Fingerprint） |

### 说明

`struct mg_client_cert` 是一个子结构体，用于在 [`mg_request_info`](mg_request_info.md) 结构体中存储客户端提供的可选证书信息。当客户端在建立连接时提供证书时，此结构体用于存储证书的相关信息。

### 参考

* [`struct mg_request_info;`](mg_request_info.md)
* [`mg_get_request_info();`](mg_get_request_info.md)
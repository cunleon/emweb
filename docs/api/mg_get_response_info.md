# Civetweb API 参考

### `mg_get_response_info(conn);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `const struct mg_connection *` | 需要获取响应信息的连接 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `const struct mg_response_info *` | 指向响应信息的指针，如果发生错误则返回 NULL |

### 说明

`mg_get_response_info()` 函数返回由 `mg_connect_client()` 打开的客户端连接上的响应信息。如果发生错误，则返回 NULL 指针。

在实现客户端时应使用此函数。

### 参考

* [`struct mg_response_info;`](mg_response_info.md)
* [`mg_connect_client();`](mg_connect_client.md)
* [`mg_get_request_info();`](mg_get_request_info.md)
* [`struct mg_request_info;`](mg_request_info.md)
# Civetweb API 参考

### `mg_get_request_info(conn);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `const struct mg_connection *` | 需要获取请求信息的连接 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `const struct mg_request_info *` | 指向请求信息的指针，如果发生错误则返回 NULL |

### 说明

`mg_get_request_info()` 函数返回指定连接上的请求信息。这些信息以指向 [`mg_request_info`](mg_request_info.md) 结构体的指针形式返回。如果发生错误，则返回 NULL 指针。

在实现服务器时应使用此函数。

### 参考

* [`struct mg_request_info;`](mg_request_info.md)
* [`mg_get_response_info();`](mg_get_response_info.md)
* [`struct mg_response_info;`](mg_response_info.md)
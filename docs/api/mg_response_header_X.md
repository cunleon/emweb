# Civetweb API 参考

### `mg_response_header_start(conn, status);`  
### `mg_response_header_add(conn, header, value, value_len);`  
### `mg_response_header_add_lines(conn, http1_headers);`  
### `mg_response_header_send(conn);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 服务器正在向此连接发送响应 |
| **`status`** | `int` | 要发送的 HTTP 状态码（100-599） |
| **`header`** | `const char *` | HTTP 头名称 |
| **`value`** | `const char *` | HTTP 头的值 |
| **`value_len`** | `int` | HTTP 头值的长度。如果为 -1，则使用整个值字符串 |
| **`http1_headers`** | `const char *` | 格式为 `"Key: Value\r\nKey2: Value2"` 的字符串 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 表示成功（>=0）或失败（<0）的整数 |
| `-1` | 错误：无效参数（例如，NULL 指针或值超出范围） |
| `-2` | 错误：无效的连接类型。这些函数只能在 Web 服务器请求处理程序中使用 |
| `-3` | 错误：无效的连接状态。这些函数必须在调用 `mg_send()` 或 `mg_printf()` 之前使用 |
| `-4` | 错误：头字段过多。头字段的总数限制为 `MG_MAX_HEADERS`（默认值：64） |
| `-5` | 错误：内存不足 |

### 说明

`mg_response_header_*` 函数系列可用于从 Web 服务器处理程序函数中发送 HTTP 响应头。这些函数不能用于 HTTP 客户端或 WebSocket。在使用 `mg_response_header_*` 函数时，必须使用它们发送所有 HTTP 头字段——不能将 `mg_response_header_*` 函数与 `mg_send_*`、`mg_write` 或 `mg_printf` 函数结合使用来发送 HTTP 头字段。发送 HTTP 头字段后，仍需使用 `mg_write` 或 `mg_printf` 发送 HTTP 正文数据。

所有 `mg_response_header_*` 函数必须在调用 `mg_write` 或 `mg_printf` 之前使用，顺序如下：

1. **`mg_response_header_start`**（仅一次）  
2. **`mg_response_header_add`**（0 到 64 次），或者使用 **`mg_response_header_add_lines`**。推荐使用 **`mg_response_header_add`**。**`mg_response_header_add_lines`** 可以处理 HTTP/1.x 格式的头字段，主要用于兼容性。  
3. **`mg_response_header_send`**（仅一次）  
4. 使用 **`mg_write`** 或 **`mg_printf`**（多次）发送 HTTP 正文数据

使用 `mg_response_header_*` 函数可以让请求处理程序处理 HTTP/1.x 和 HTTP/2 请求，而直接使用 `mg_printf` 或 `mg_write` 发送 HTTP 头字段则无法实现这一点。

### 参考

* [`mg_send_http_ok();`](mg_send_http_ok.md)
* [`mg_send_http_error();`](mg_send_http_error.md)
* [`mg_send_http_redirect();`](mg_send_http_redirect.md)
* [`mg_write();`](mg_write.md)
* [`mg_send_chunk();`](mg_send_chunk.md)
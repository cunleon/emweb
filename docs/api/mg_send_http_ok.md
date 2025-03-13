# Civetweb API 参考

### `mg_send_http_ok(conn, mime_type, content_len);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 用于发送数据的连接 |
| **`mime_type`** | `const char *` | 要发送的内容类型（例如，`"text/plain"`、`"text/html"`、`"application/json"` 等） |
| **`content_len`** | `long long` | 响应正文数据的长度（以字节为单位） |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 表示成功（>=0）或失败（<0）的整数 |

### 说明

`mg_send_http_ok()` 函数用于发送一个 "HTTP 200 OK" 响应头，包括典型的响应头字段，如日期、长度、内容类型、"no caching" 以及服务器配置中定义的其他头字段。

- **`mime_type`**：必须提供合适的内容类型，例如 `"text/plain"`、`"text/html"` 或 `"application/json"` 等。
- **`content_len`**：指定响应正文的大小（以字节为单位）。如果大小尚未确定，可以提供 `-1` 以选择分块传输编码。
- 在调用 `mg_send_http_ok()` 之后，服务器回调必须发送正文数据。如果已知 `content_len`，则通常使用 [`mg_write`](mg_write.md)；如果内容长度未知，则使用分块传输编码，通过调用 [`mg_send_chunk`](mg_send_chunk.md) 发送正文数据。

### 示例代码

```c
// 发送一个简单的 HTML 响应
mg_send_http_ok(conn, "text/html", -1);  // 使用分块传输编码
mg_send_chunk(conn, "<html><body><h1>Hello, World!</h1></body></html>", 40);
mg_send_chunk(conn, NULL, 0);  // 发送最后一个分块，结束响应
```

### 参考

* [`mg_send_http_error();`](mg_send_http_error.md)
* [`mg_send_http_redirect();`](mg_send_http_redirect.md)
* [`mg_write();`](mg_write.md)
* [`mg_send_chunk();`](mg_send_chunk.md)
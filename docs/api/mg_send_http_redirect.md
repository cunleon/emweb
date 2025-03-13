# Civetweb API 参考

### `mg_send_http_redirect(conn, target_url, redirect_code);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 用于发送数据的连接 |
| **`target_url`** | `const char *` | 新的目标位置 |
| **`redirect_code`** | `int` | HTTP 重定向响应码 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 表示成功（>=0）或失败（<0）的整数 |

### 说明

`mg_send_http_redirect()` 函数用于发送 "HTTP 30x ..." 重定向响应。

客户端（浏览器）将被重定向到由 `target_url` 指定的新位置。该位置可以是相对 URL 或绝对 URL。

参数 `redirect_code` 定义了发送的重定向类型：

| `redirect_code` | 类型 | HTTP 方法 |
| :---: | :--- | :--- |
| 301 | 永久重定向 | - |
| 302 | 临时重定向 | - |
| 303 | 临时重定向 | 始终使用 GET |
| 307 | 临时重定向 | 使用相同方法 |
| 308 | 永久重定向 | 使用相同方法 |

状态码 301 和 302 定义于 HTTP/1.0，而状态码 303、307 和 308 定义于 HTTP/1.1。对于 HTTP/1.1 的重定向，明确指定了重定向的 POST 请求是否应保持为 POST 请求（307、308）还是应改为 GET 请求（303）到新目标位置。不建议在非 GET 请求中使用 302，因为某些浏览器将其实现为 303，而另一些浏览器将其实现为 307。

### 示例代码

```c
mg_send_http_redirect(conn, "https://example.com/new_location", 302);
```

### 参考

* [`mg_send_http_error();`](mg_send_http_error.md)
* [`mg_send_http_ok();`](mg_send_http_ok.md)
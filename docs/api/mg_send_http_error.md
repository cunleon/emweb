# Civetweb API 参考

### `mg_send_http_error(conn, status_code, fmt, ...);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 用于发送数据的连接 |
| **`status_code`** | `int` | HTTP 状态码（参见 HTTP 标准） |
| **`fmt`** | `const char *` | 错误消息的格式化字符串 |
| **`...`** | *可变参数* | 根据格式化字符串指定的参数 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 表示成功（>=0）或失败（<0）的整数 |

### 说明

`mg_send_http_error()` 函数用于从服务器向客户端发送 HTTP 错误消息。`status_code` 必须是预定义的 HTTP 标准错误码之一（例如，“404” 表示 “Not Found”）。该函数已知标准错误码的状态文本（例如，“Not Found”）。可以使用 `fmt` 格式化字符串和附加参数指定错误消息的正文，以更详细地说明错误。`fmt` 格式化字符串的工作方式与标准 C 库中的 `printf()` 函数类似。

### 示例代码

```c
mg_send_http_error(conn, 404, "The requested resource %s was not found on this server.", requested_resource);
```

### 参考

* [`mg_send_http_ok();`](mg_send_http_ok.md)
* [`mg_send_http_redirect();`](mg_send_http_redirect.md)
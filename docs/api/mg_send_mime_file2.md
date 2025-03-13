# Civetweb API 参考

### `mg_send_mime_file2(conn, path, mime_type, additional_headers);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 用于发送文件的连接 |
| **`path`** | `const char *` | 文件的完整路径和文件名 |
| **`mime_type`** | `const char *` | 文件的 MIME 类型，或为 NULL 以自动检测 |
| **`additional_headers`** | `const char *` | 要发送的额外 HTTP 头字段 |

### 返回值

*无*

### 说明

`mg_send_mime_file2()` 函数用于通过连接发送文件，同时支持发送用户指定的额外 HTTP 头字段。该函数与 [`mg_send_mime_file()`](mg_send_mime_file.md) 类似，但增加了发送自定义头字段的功能。如果 `mime_type` 参数为 NULL，函数将根据文件扩展名自动检测 MIME 类型。

额外的自定义头字段可以通过 `additional_headers` 参数指定。请确保这些头字段的名称以 `X-` 开头，以避免与其他标准头字段冲突。如果 `additional_headers` 参数为 NULL，则不会添加任何自定义头字段。

### 示例代码

```c
const char *additional_headers = "X-Custom-Header: CustomValue\r\n";
mg_send_mime_file2(conn, "/path/to/file.html", "text/html", additional_headers);
```

### 参考

* [`mg_get_builtin_mime_type();`](mg_get_builtin_mime_type.md)
* [`mg_printf();`](mg_printf.md)
* [`mg_send_file();`](mg_send_file.md)
* [`mg_send_mime_file();`](mg_send_mime_file.md)
* [`mg_write();`](mg_write.md)
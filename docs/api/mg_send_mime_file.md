# Civetweb API 参考

### `mg_send_mime_file(conn, path, mime_type);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 用于发送文件的连接 |
| **`path`** | `const char *` | 文件的完整路径和文件名 |
| **`mime_type`** | `const char *` | 文件的 MIME 类型，或为 NULL 以自动检测 |

### 返回值

*无*

### 说明

`mg_send_mime_file()` 函数通过连接发送文件，包括 HTTP 头。该函数与 [`mg_send_file()`](mg_send_file.md) 类似，但增加了可以指定文件 MIME 类型的功能。如果 `mime_type` 参数为 NULL，函数将尝试根据文件扩展名自动检测 MIME 类型。

### 示例代码

```c
mg_send_mime_file(conn, "/path/to/file.html", "text/html");
```

### 参考

* [`mg_get_builtin_mime_type();`](mg_get_builtin_mime_type.md)
* [`mg_printf();`](mg_printf.md)
* [`mg_send_file();`](mg_send_file.md)
* [`mg_send_mime_file2();`](mg_send_mime_file2.md)
* [`mg_write();`](mg_write.md)
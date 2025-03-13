# Civetweb API 参考

### `mg_send_file(conn, path);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 用于发送文件的连接 |
| **`path`** | `const char *` | 文件的完整路径和文件名 |

### 返回值

*无*

### 说明

`mg_send_file()` 函数通过连接将文件的内容发送给远程对端。该函数还会添加必要的 HTTP 头。

### 参考

* [`mg_send_file_body();`](mg_send_file_body.md)
* [`mg_send_mime_file();`](mg_send_mime_file.md)
* [`mg_send_mime_file2();`](mg_send_mime_file2.md)
* [`mg_printf();`](mg_printf.md)
* [`mg_write();`](mg_write.md)
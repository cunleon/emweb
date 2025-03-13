# Civetweb API 参考

### `mg_send_file_body(conn, path);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 用于发送文件的连接 |
| **`path`** | `const char *` | 文件的完整路径和文件名 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 表示成功（>=0）或失败（<0）的整数 |

### 说明

`mg_send_file_body()` 函数通过连接将文件的内容发送给远程对端，但不会添加任何 HTTP 头。在使用此函数之前，代码必须发送所有必需的 HTTP 响应头。

### 参考

* [`mg_send_file();`](mg_send_file.md)
* [`mg_send_mime_file();`](mg_send_mime_file.md)
* [`mg_send_mime_file2();`](mg_send_mime_file2.md)
* [`mg_printf();`](mg_printf.md)
* [`mg_write();`](mg_write.md)
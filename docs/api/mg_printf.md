# Civetweb API 参考

### `mg_printf(conn, fmt, ...);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 用于发送数据的连接 |
| **`fmt`** | `const char *` | 格式化字符串 |
| **`...`** | *可变参数* | 根据格式化字符串指定的参数 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 写入的字节数或错误代码 |

### 说明

`mg_printf()` 函数用于通过连接发送格式化字符串。其功能与标准 C 库中的 `printf()` 函数族类似。函数返回值如下：
- 如果连接已关闭，返回 **0**。
- 如果发生错误，返回 **-1**。
- 否则，返回通过连接写入的字节数。

除了格式化部分外，`mg_printf()` 函数与函数 [`mg_write()`](mg_write.md) 完全相同。

### 参考

* [`mg_websocket_client_write();`](mg_websocket_client_write.md)
* [`mg_websocket_write();`](mg_websocket_write.md)
* [`mg_write();`](mg_write.md)
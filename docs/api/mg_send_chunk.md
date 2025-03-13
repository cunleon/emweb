# Civetweb API 参考

### `mg_send_chunk(conn, buf, len);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 指向用于发送数据的连接的指针 |
| **`buf`** | `const void *` | 指向要发送的数据块的指针 |
| **`len`** | `size_t` | 要发送的字节数 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 发送的字节数，或失败标志 |

### 说明

`mg_send_chunk()` 函数用于通过连接发送任意数据块。**仅在发送了带有 `"Transfer-Encoding: chunked"` 的完整 HTTP 请求或响应头之后使用此函数**。否则，请使用 `mg_write()`。

函数返回值如下：
- 如果数据已发送，返回值 **>0**。
- 如果连接已关闭，返回值为 **0**。
- 如果发生错误，返回值为 **-1**。

### 参考

* [`mg_write();`](mg_write.md)
* [`mg_printf();`](mg_printf.md)
* [`mg_lock_connection();`](mg_lock_connection.md)
* [`mg_unlock_connection();`](mg_unlock_connection.md)
# Civetweb API 参考

### `mg_lock_connection(conn);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 需要获取锁的连接 |

### 返回值

*无*

### 说明

`mg_lock_connection()` 函数专门用于 WebSocket 连接，以锁定连接。如果代码中有服务器主动发起的通信，或者直接响应消息的通信，则在调用 [`mg_write()`](mg_write.md) 和 [`mg_printf()`](mg_printf.md) 时，必须与 [`mg_unlock_connection();`](mg_unlock_connection.md) 配合使用。

### 参考

* [`mg_lock_context();`](mg_lock_context.md)
* [`mg_printf();`](mg_printf.md)
* [`mg_unlock_connection();`](mg_unlock_connection.md)
* [`mg_unlock_context();`](mg_unlock_context.md)
* [`mg_websocket_client_write();`](mg_websocket_client_write.md)
* [`mg_websocket_write();`](mg_websocket_write.md)
* [`mg_write();`](mg_write.md)
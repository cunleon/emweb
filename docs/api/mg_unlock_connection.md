# Civetweb API 参考

### `mg_unlock_connection( conn );`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
|**`conn`**|`struct mg_connection *`|需要解锁的连接|

### 返回值

*无*

### 描述

函数 `mg_unlock_connection()` 用于移除通过 [`mg_lock_connection()`](mg_lock_connection.md) 设置的连接锁。在使用 [`mg_write()`](mg_write.md) 或 [`mg_printf()`](mg_printf.md) 对 WebSocket 连接进行写操作时，锁定可能是必要的，以防止数据损坏。

### 相关函数

* [`mg_lock_connection();`](mg_lock_connection.md)
* [`mg_lock_context();`](mg_lock_context.md)
* [`mg_printf();`](mg_printf.md)
* [`mg_unlock_context();`](mg_unlock_context.md)
* [`mg_websocket_client_write();`](mg_websocket_client_write.md)
* [`mg_websocket_write();`](mg_websocket_write.md)
* [`mg_write();`](mg_write.md)
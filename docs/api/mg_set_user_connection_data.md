# Civetweb API 参考

### `mg_set_user_connection_data(conn, data);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 要附加用户数据的连接 |
| **`data`** | `void *` | 指向用户数据的指针 |

### 返回值

*无*

### 描述

`mg_set_user_connection_data()` 函数可用于将用户自定义数据指针附加到连接上。此值可以通过 `mg_get_user_connection_data()` 读取。任何对 `mg_set_user_connection_data()` 的调用都会覆盖之前分配的用户数据指针。

`mg_set_user_connection_data()` 需要一个非 `const` 的 `struct mg_connection *` 来设置用户数据指针。在 WebSocket 连接处理器中传递的 `const struct mg_connection *` 可以安全地使用（通过 `const` 强制转换），因为 `const` 只意味着在此上下文中不能使用 `mg_read()` 或 `mg_write()`。

此外，也可以通过 `struct mg_callbacks` 中的 `init_connection` 回调函数来设置用户数据指针。在这种情况下，通常使用 `init_connection` 分配用户定义的 `struct` 的内存，而 `connection_close` 则用于释放该内存。

### 参见

* [`mg_get_user_connection_data();`](mg_get_user_connection_data.md)
* [`struct mg_callbacks`](mg_callbacks.md)
* [`mg_set_websocket_handler();`](mg_set_websocket_handler.md)
* [`mg_read();`](mg_read.md)
* [`mg_write();`](mg_write.md)
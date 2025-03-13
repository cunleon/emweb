# Civetweb API 参考

### `mg_set_websocket_handler_with_subprotocols(ctx, uri, subprotocols, connect_handler, ready_handler, data_handler, close_handler, cbdata);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`ctx`** | `mg_context *` | 要添加处理器的上下文 |
| **`uri`** | `const char *` | 需要激活处理器的 URI |
| **`subprotocols`** | `struct mg_websocket_subprotocols *` | 支持的子协议列表 |
| **`connect_handler`** | `mg_websocket_connect_handler` | 在连接建立时被调用的处理器 |
| **`ready_handler`** | `mg_websocket_ready_handler` | 在连接准备就绪时被调用的处理器 |
| **`data_handler`** | `mg_websocket_data_handler` | 在接收到数据时被调用的处理器 |
| **`close_handler`** | `mg_websocket_close_handler` | 在连接关闭时被调用的处理器 |
| **`cbdata`** | `void *` | 用户自定义数据 |

`int mg_websocket_connect_handler(const struct mg_connection *conn, void *cbdata);`  
`int mg_websocket_ready_handler(struct mg_connection *conn, void *cbdata);`  
`int mg_websocket_data_handler(struct mg_connection *conn, int opcode, char *buf, size_t buf_len, void *cbdata);`  
`int mg_websocket_close_handler(const struct mg_connection *conn, void *cbdata);`

### 返回值

*无*

### 描述

`mg_set_websocket_handler_with_subprotocols()` 函数将回调函数绑定到 WebSocket URI，类似于 [`mg_set_websocket_handler();`](mg_set_websocket_handler.md)。此外，它还允许指定 WebSocket 子协议。当 URI 上检测到状态变化（例如，有新的连接或从远端对等方接收到数据）时，会调用这些回调函数。

### 参见

* [`struct mg_websocket_subprotocols;`](api/mg_websocket_subprotocols.md)
* [`mg_set_websocket_handler();`](mg_set_websocket_handler.md)
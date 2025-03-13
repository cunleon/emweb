# Civetweb API 参考

### `mg_set_websocket_handler(ctx, uri, connect_handler, ready_handler, data_handler, close_handler, cbdata);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`ctx`** | `mg_context *` | 要添加处理程序的上下文 |
| **`uri`** | `const char *` | 要激活处理程序的 URI |
| **`connect_handler`** | `mg_websocket_connect_handler` | 当连接被触发时调用的处理程序 |
| **`ready_handler`** | `mg_websocket_ready_handler` | 当连接准备就绪时调用的处理程序 |
| **`data_handler`** | `mg_websocket_data_handler` | 当接收到数据时调用的处理程序 |
| **`close_handler`** | `mg_websocket_close_handler` | 当连接关闭时调用的处理程序 |
| **`cbdata`** | `void *` | 用户自定义数据 |

```c
int mg_websocket_connect_handler(const struct mg_connection *conn, void *cbdata);
int mg_websocket_ready_handler(struct mg_connection *conn, void *cbdata);
int mg_websocket_data_handler(struct mg_connection *conn, int opcode, char *buf, size_t buf_len, void *cbdata);
int mg_websocket_close_handler(const struct mg_connection *conn, void *cbdata);
```

### 返回值

无

### 描述

`mg_set_websocket_handler()` 函数将回调函数连接到 WebSocket URI。当 URI 上检测到状态变化（如传入连接或从远程对等方接收数据）时，回调函数会被调用。

### 参见

* [mg_set_websocket_handler_with_subprotocols()](mg_set_websocket_handler_with_subprotocols.md)
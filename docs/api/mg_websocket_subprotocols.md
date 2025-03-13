# Civetweb API 参考

### `struct mg_websocket_subprotocols;`

### 字段

| 字段 | 类型 | 描述 |
| :--- | :--- | :--- |
|**`nb_subprotocols`**|`int`| 后续支持的 WebSocket 子协议数量（>=0）。 |
|**`subprotocols`**|`const char **`| WebSocket 子协议名称数组（包含 `nb_subprotocols` 个元素）。 |

### 描述

结构体 `mg_websocket_subprotocols` 用于指定 WebSocket 处理函数支持的 WebSocket 子协议。

### 相关函数

* [`mg_set_websocket_handler_with_subprotocols();`](mg_set_websocket_handler_with_subprotocols.md)
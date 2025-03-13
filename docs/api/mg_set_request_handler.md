# Civetweb API 参考

### `mg_set_request_handler(ctx, uri, handler, cbdata);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`ctx`** | `struct mg_context *` | 需要激活处理器的上下文 |
| **`uri`** | `const char *` | 需要绑定处理器的 URI |
| **`handler`** | `mg_request_handler` | 执行主要工作的回调函数 |
| **`cbdata`** | `void *` | 可选的用户自定义数据 |

`int mg_request_handler(struct mg_connection *conn, void *cbdata);`

### 返回值

*无*

### 描述

`mg_set_request_handler()` 函数将一个回调函数绑定到一个 URI 上。每当客户端请求该特定 URI 时，回调函数就会被调用。回调函数接收连接信息和可选的用户自定义数据作为参数，并可以向客户端返回信息。如果回调函数没有向客户端返回任何信息，则应返回 **0**，以通知 Civetweb 核心处理该请求。返回值在 1 到 999 之间表示请求已被处理，无需进一步处理。返回的代码将作为状态码存储在访问日志中，因此建议（但不是强制要求）返回与请求状态匹配的状态码。

### 参见

* [`mg_set_auth_handler();`](mg_set_auth_handler.md)
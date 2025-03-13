# Civetweb API 参考

### `struct mg_callbacks;`

### 字段

| 字段 | 描述 |
| :--- | :--- |
| **`begin_request`** | **`int (*begin_request)(struct mg_connection *conn);`** |
| | `begin_request()` 回调函数在 CivetWeb 接收到新的 HTTP 请求时被调用。如果回调函数未处理请求，则应返回 0，此时 CivetWeb 将使用默认回调例程处理请求。如果回调函数返回 1 到 999 之间的值，则 CivetWeb 不会进行任何操作，回调函数应完成所有处理，包括发送适当的 HTTP 头等。从 CivetWeb 1.7 版本开始，`begin_request()` 在任何授权检查之前被调用。如果需要授权检查，应使用 `request_handler()`。回调函数的返回值不仅用于通知 CivetWeb 不再进一步处理请求，还会被存储为访问日志中的 HTTP 状态码。 |
| **`end_request`** | **`void (*end_request)(const struct mg_connection *conn, int reply_status_code);`** |
| | `end_request()` 回调函数在 CivetWeb 完全处理完请求后被调用，并将发送给客户端的响应状态码传递给应用程序。 |
| **`log_message`** | **`int (*log_message)(const struct mg_connection *conn, const char *message);`** |
| | `log_message()` 回调函数在 CivetWeb 即将记录消息时被调用。如果回调函数返回 0，CivetWeb 将使用默认的内部日志记录例程记录消息。如果返回非零值，CivetWeb 假设日志记录已经完成，不会采取进一步操作。 |
| **`log_access`** | **`int (*log_access)(const struct mg_connection *conn, const char *message);`** |
| | `log_access()` 回调函数在 CivetWeb 即将记录访问消息时被调用。如果回调函数返回 0，CivetWeb 将使用默认的内部访问日志记录例程记录访问。如果返回非零值，CivetWeb 假设访问日志记录已经完成，不会采取进一步操作。 |
| **`init_ssl`** | **`int (*init_ssl)(void *ssl_ctx, void *user_data);`** |
| | `init_ssl()` 回调函数在 CivetWeb 初始化 SSL 库时被调用。`ssl_ctx` 参数是指向正在配置的 SSL 上下文的指针。`user_data` 参数包含在服务器启动时传递给 `mg_start()` 的数据指针。回调函数可以返回 0，通知 CivetWeb 设置 SSL 证书。返回值为 1 表示证书已设置，无需进一步处理。SSL 初始化失败时应返回 -1。 |
| **`init_ssl_domain`** | **`int (*init_ssl_domain)(const char *server_domain, void *ssl_ctx, void *user_data);`** |
| | `init_ssl_domain()` 回调函数在 CivetWeb 初始化 SSL 库时被调用。`server_domain` 参数是指向正在配置的域的 `authentication_domain` 配置参数的指针。`ssl_ctx` 参数是指向正在配置的 SSL 上下文的指针。`user_data` 参数包含在服务器启动时传递给 `mg_start()` 的数据指针。回调函数可以返回 0，通知 CivetWeb 设置 SSL 证书。返回值为 1 表示证书已设置，无需进一步处理。SSL 初始化失败时应返回 -1。 |
| **`external_ssl_ctx`** | **`int (*external_ssl_ctx)(void **ssl_ctx, void *user_data);`** |
| | `external_ssl_ctx()` 回调函数在 CivetWeb 创建（`*ssl_ctx` 为 `NULL`）或释放（`*ssl_ctx` 不为 `NULL`）SSL 上下文时被调用。`user_data` 参数包含在服务器启动时传递给 `mg_start()` 的数据指针。回调函数可以返回 0，通知 CivetWeb 设置 SSL 上下文。返回值为 1 表示 SSL 上下文已设置，无需进一步处理。此时，其他回调函数 `init_ssl()` 和 `init_ssl_domain()` 也不会被调用。SSL 上下文初始化失败时应返回 -1。 |
| **`external_ssl_ctx_domain`** | **`int (*external_ssl_ctx_domain)(const char *server_domain, void **ssl_ctx, void *user_data);`** |
| | `external_ssl_ctx_domain()` 回调函数在 CivetWeb 创建（`*ssl_ctx` 为 `NULL`）或释放（`*ssl_ctx` 不为 `NULL`）SSL 上下文时被调用。`server_domain` 参数是指向正在创建或释放的域的 `authentication_domain` 配置参数的指针。`user_data` 参数包含在服务器启动时传递给 `mg_start()` 的数据指针。回调函数可以返回 0，通知 CivetWeb 设置 SSL 上下文。返回值为 1 表示 SSL 上下文已设置，无需进一步处理。此时，其他回调函数 `init_ssl()` 和 `init_ssl_domain()` 也不会被调用。SSL 上下文初始化失败时应返回 -1。 |
| **`connection_close`** | **`void (*connection_close)(const struct mg_connection *conn);`** |
| | `connection_close()` 回调函数在 CivetWeb 关闭连接之前被调用。调用回调函数时，上下文互斥锁已被锁定。该函数主要用于记录 WebSocket 关闭事件，并从应用程序维护的客户端列表中移除。*使用此回调处理 WebSocket 连接已被弃用，建议使用 `mg_set_websocket_handler()` 替代。* |
| **`connection_closed`** | **`void (*connection_closed)(const struct mg_connection *conn);`** |
| | `connection_closed()` 回调函数在 CivetWeb 关闭连接后（SSL 关闭和套接字关闭后）被调用。调用回调函数时，上下文互斥锁已被锁定。 |
| **`init_lua`** | **`void (*init_lua)(const struct mg_connection *conn, void *lua_context, unsigned context_flags);`** |
| | `init_lua()` 回调函数在即将提供 Lua 服务器页面时被调用。必须在编译时启用 Lua 页面服务，此回调函数才会被调用。`lua_context` 参数是一个 `lua_State *` 指针。`context_flags` 参数表示 Lua 环境的类型。 |
| **`exit_lua`** | **`void (*exit_lua)(const struct mg_connection *conn, void *lua_context, unsigned context_flags);`** |
| | `exit_lua()` 回调函数在 Lua 状态即将关闭时被调用。必须在编译时启用 Lua 页面服务，此回调函数才会被调用。参数与 `init_lua()` 相同。 |
| **`http_error`** | **`int (*http_error)(struct mg_connection *conn, int status, const char *msg);`** |
| | `http_error()` 回调函数在 CivetWeb 即将向客户端发送 HTTP 错误时被调用。该函数允许应用程序发送自定义错误页面。错误状态码作为参数提供。如果应用程序发送了自己的错误页面，则必须返回 0，通知 CivetWeb 不再进行进一步处理。如果返回值不为 0，CivetWeb 将向客户端发送错误页面。 |
| **`init_context`** | **`void (*init_context)(const struct mg_context *ctx);`** |
| | `init_context()` 回调函数在 CivetWeb 服务器启动并初始化后，但在处理任何请求之前被调用。这允许应用程序在处理第一个请求之前执行一些初始化操作。 |
| **`exit_context`** | **`void (*exit_context)(const struct mg_context *ctx);`** |
| | `exit_context()` 回调函数在 CivetWeb 服务器停止时被调用。它允许应用程序在服务器关闭时执行一些清理操作。 |
| **`init_thread`** | **`void * (*init_thread)(const struct mg_context *ctx, int thread_type);`** |
| | `init_thread()` 回调函数在 CivetWeb 创建新线程时被调用。它始终在新创建的线程中调用，可用于初始化线程本地存储数据。`thread_type` 参数表示创建的线程类型，支持以下线程类型： |
| | **0** - 创建主线程 |
| | **1** - 创建处理客户端连接的工作线程 |
| | **2** - 创建内部辅助线程（计时器线程） |
| | **3** - 创建 WebSocket 客户端线程 |
| | 返回的 `void *` 指针将作为用户定义的指针存储在线程本地存储中。 |
| **`exit_thread`** | **`void (*exit_thread)(const struct mg_context *ctx, int thread_type, void *user_ptr);`
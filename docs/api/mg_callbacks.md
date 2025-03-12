# Civetweb API Reference

### `struct mg_callbacks;`

### Fields

| Field | Description |
| :--- | :--- |
|**`begin_request`**|**`int (*begin_request)( struct mg_connection *conn );`**|
| |当 CivetWeb 收到新的 HTTP 请求时，将调用 'begin_request（）' 回调函数。如果回调函数未处理请求，则应返回 0。在这种情况下，CivetWeb 将使用默认回调例程处理请求。如果回调函数返回 1 到 999 之间的值，则 CivetWeb 不执行任何作，回调函数应执行所有处理，包括发送正确的 HTTP 标头等。从 CivetWeb 版本 1.7 开始，函数 'begin_request（）' 在完成任何授权之前被调用。如果需要授权检查，则应改用 'request_handler（）'。回调函数的返回值不仅用于向 CivetWeb 发出信号，使其不再进一步处理请求。返回的值也作为 HTTP 状态代码存储在访问日志中。 |

|**`end_request`**|**`void (*end_request)(const struct mg_connection *conn, int reply_status_code);`**|
| |T当请求被完全处理时，CivetWeb 会调用回调函数 'end_request（）'。它将发送到客户端的回复状态代码发送到应用程序。|

|**`log_message`**|**`int (*log_message)( const struct mg_connection *conn, const char *message );`**|
| |回调函数 'log_message（）' 在 CivetWeb 即将记录消息时调用。如果回调函数返回 0，CivetWeb 将使用默认的内部日志例程来记录消息。如果返回非零值，则 CivetWeb 假定日志记录已完成，并且不会执行进一步的作。|

|**`log_access`**|**`int (*log_access)( const struct mg_connection *conn, const char *message );`**|
| |T回调函数 'log_access（）' 在 CivetWeb 即将记录消息时调用。如果回调函数返回 0，CivetWeb 将使用默认的内部访问日志例程来记录访问。如果返回非零值，则 CivetWeb 假定已经完成了访问日志记录，并且不执行进一步的作。|

|**`init_ssl`**|**`int (*init_ssl)( void *ssl_ctx, void *user_data );`**|
| |T当 CivetWeb 初始化 SSL 库时，将调用回调函数 'init_ssl（）'。'ssl_ctx' 参数是指向正在配置的 SSL 上下文的指针。参数 'user_data' 包含一个指针，该指针指向服务器启动时提供给 'mg_start（）' 的数据。回调函数可以返回 0 以表示 CivetWeb 应该设置 SSL 证书。如果返回值为 1，则回调函数会向 CivetWeb 发出信号，表明证书已设置完毕，无需进一步处理。当 SSL 初始化失败时，应返回值 -1。|

|**`init_ssl_domain`**|**`int (*init_ssl_domain)( const char *server_domain, void *ssl_ctx, void *user_data );`**|
| |当 CivetWeb 初始化 SSL 库时，将调用回调函数 'init_ssl_domain（）'。参数 'server_domain' 是指向正在配置的域的 'authentication_domain' 配置参数的指针。'ssl_ctx' 参数是指向正在配置的 SSL 上下文的指针。参数 'user_data' 包含一个指针，该指针指向服务器启动时提供给 'mg_start（）' 的数据。回调函数可以返回 0 以表示 CivetWeb 应该设置 SSL 证书。如果返回值为 1，则回调函数会向 CivetWeb 发出信号，表明证书已设置完毕，无需进一步处理。当 SSL 初始化失败时，应返回值 -1。|

|**`external_ssl_ctx`**|**`int (*external_ssl_ctx)( void **ssl_ctx, void *user_data );`**|
| |当 civetweb 即将创建 （'*ssl_ctx' 为 'NULL'） 或释放 （'*ssl_ctx' 不是 'NULL'） SSL 上下文时，将调用回调函数 'external_ssl_ctx（）'。参数 'user_data' 包含一个指针，该指针指向服务器启动时提供给 'mg_start（）' 的数据。回调函数可以返回 0 以表示 CivetWeb 应该设置 SSL 上下文。如果返回值为 1，则回调函数会向 CivetWeb 发出信号，表明 SSL 上下文已经设置完毕，无需进一步处理。此外，当返回值为 1 时，不会调用其他回调函数 'init_ssl（）' 和 'init_ssl_domain（）'。当 SSL 上下文初始化失败时，应返回值 -1。|

|**`external_ssl_ctx_domain`**|**`int (*external_ssl_ctx_domain)( const char *server_domain, void **ssl_ctx, void *user_data );`**|
| |当 civetweb 即将创建 （'*ssl_ctx' 为 'NULL'） 或释放 （'*ssl_ctx' 不是 'NULL'） SSL 上下文时，将调用回调函数 'external_ssl_ctx_domain（）'。参数 'server_domain' 是指向正在创建或释放的域的 'authentication_domain' 配置参数的指针。参数 'user_data' 包含一个指针，该指针指向服务器启动时提供给 'mg_start（）' 的数据。回调函数可以返回 0 以表示 CivetWeb 应该设置 SSL 上下文。如果返回值为 1，则回调函数会向 CivetWeb 发出信号，表明 SSL 上下文已经设置完毕，无需进一步处理。此外，当返回值为 1 时，不会调用其他回调函数 'init_ssl（）' 和 'init_ssl_domain（）'。当 SSL 上下文初始化失败时，应返回值 -1。|

|**`connection_close`**|**`void (*connection_close)( const struct mg_connection *conn );`**|
| |回调函数 'connection_close（）' 在 CivetWeb 关闭连接之前被调用。调用回调函数时，每个上下文的互斥锁被锁定。该函数主要用于记录 websocket 何时关闭并将其从任何应用程序维护的客户端列表中删除。*此回调用于 websocket 连接已弃用。使用* 'mg_set_websocket_handler（）' *代替。*|

|**`connection_closed`**|**`void (*connection_closed)( const struct mg_connection *conn );`**|
| |回调函数 'connection_closed（）' 在 CivetWeb 关闭连接后（在 SSL 关闭和关闭套接字之后）被调用。调用回调函数时，每个上下文的互斥锁将被锁定。|

|**`init_lua`**|**`void (*init_lua)( const struct mg_connection *conn, void *lua_context, unsigned context_flags );`**|
| |The callback function `init_lua()` is called just before a Lua server page is to be served. Lua page serving must have been enabled at compile time for this callback function to be called. The parameter `lua_context` is a `lua_State *` pointer. The parameter `context_flags` indicate the type of Lua environment. |
|**`exit_lua`**|**`void (*init_lua)( const struct mg_connection *conn, void *lua_context, unsigned context_flags );`**|
| |The callback function `exit_lua()` is called when a Lua state is about to be closed. Lua page serving must have been enabled at compile time for this callback function to be called. The parameters are identical to `lua_init()`.|
|**`http_error`**|**`int (*http_error)( struct mg_connection *conn, int status, const char *msg );`**|
| |T回调函数 'http_error（）' 由 CivetWeb 在将 HTTP 错误发送到客户端之前调用。该函数允许应用程序发送自定义错误页面。错误的状态代码作为参数提供。如果应用程序发送自己的错误页面，则必须返回 0 以向 CivetWeb 发出信号，表明不需要进一步处理。如果返回值不为 0，CivetWeb 将向客户端发送错误页面。|

|**`init_context`**|**`void (*init_context)( const struct mg_context *ctx );`**|
| |回调函数 'init_context（）' 在 CivetWeb 服务器启动和初始化之后，但在提供任何请求之前调用。这允许应用程序在处理第一个请求之前执行一些初始化活动。|

|**`exit_context`**|**`void (*exit_context)( const struct mg_context *ctx );`**|
| |当服务器停止时，CivetWeb 会调用 'exit_context（）' 回调函数。它允许应用程序在应用程序端进行一些清理。|

|**`init_thread`**|**`void * (*init_thread)( const struct mg_context *ctx, int thread_type );`**|
| |T回调函数 'init_thread（）' 在 CivetWeb 创建新线程时调用。它始终从新创建的线程中调用，可用于初始化线程本地存储数据。'thread_type' 参数指示已创建的线程类型。可识别以下线程类型：| | |**0** - 主线程已创建 | | |**1** - 已创建处理客户端连接的工作线程| | |**2** - 已创建内部帮助线程（计时器线程）| | |**3** - 已创建 websocket 客户端线程| | |返回的 'void *' 作为用户定义的指针存储在线程本地存储中。|

|**`exit_thread`**|**`void (*exit_thread)( const struct mg_context *ctx, int thread_type, void * user_ptr);`**|
| |The callback function `exit_thread()` is called when a thread is about to exit. The parameters correspond to `init_thread`, with `user_ptr` being the return value.|
|**`init_connection`**|**`int (*init_connection)( struct mg_cconnection *conn, void ** conn_data);`**|
| |The callback function `init_connection()` is called when a new connection is created. It can be used to set user defined connection data (type `void *`) by setting `*conn_data`.|


### Description

Civetweb 库中的大部分功能都是通过回调函数提供的。应用程序在 Civetweb 库中注册自己的处理函数，当事件发生时，将调用相应的回调函数。通过这种方式，应用程序能够将其处理代码放在 Web 服务器的核心，而无需更改 Web 服务器本身的代码。启动 civetweb 子系统时，会注册许多回调函数。Other 可以在运行时使用 helper 函数添加或更改。

指向 'mg_callbacks' 结构的指针作为参数传递给 ['mg_start（）']（mg_start.md） 函数，以提供指向 Web 服务器将在特定事件中调用的回调函数的链接。如果未提供特定的回调函数，CivetWeb 将回退到默认的内部回调例程。回调函数使应用程序能够详细控制应如何处理特定事件。

Much of the functionality in the Civetweb library is provided through callback functions. The application registers their own processing functions with the Civetweb library and when an event happens, the appropriate callback function is called. In this way an application is able to have their processing code right at the heart of the webserver, without the need to change the code of the webserver itself. A number of callback functions are registered when the civetweb subsystem is started. Other may be added or changed at runtime with helper functions.

A pointer to a `mg_callbacks` structure is passed as parameter to the [`mg_start()`](mg_start.md) function to provide links to callback functions which the webserver will call at specific events. If a specific callback function is not supplied, CivetWeb will fallback to default internal callback routines. Callback functions give the application detailed control over how specific events should be handled.

### See Also

* [`mg_start();`](mg_start.md)
* [`mg_stop();`](mg_stop.md)

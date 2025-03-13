# Civetweb API 参考

### `mg_set_auth_handler(ctx, uri, handler, cbdata);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`ctx`** | `struct mg_context *` | 要设置处理器的上下文 |
| **`uri`** | `const char *` | 授权处理器对应的 URI |
| **`handler`** | `mg_authorization_handler` | 执行实际授权的回调函数 |
| **`cbdata`** | `void *` | 可选的用户数据 |

回调函数类型：
```c
int mg_authorization_handler(struct mg_connection *conn, void *cbdata);
```

### 返回值

*无*

### 说明

`mg_set_auth_handler()` 函数将授权函数绑定到指定的 URI，用于检查用户是否有权限访问该 URI。授权检查由类型为 `mg_authorization_handler` 的回调函数执行。回调函数接收两个参数：当前连接和一个指向用户定义数据的指针（该指针是在调用 `mg_set_auth_handler()` 时传递的）。

回调函数可以返回：
- **0**：拒绝访问
- **1**：允许访问

为了在拒绝访问时提供最大的灵活性，回调函数应自行发送 HTTP 响应。例如：
- 可以使用 [`mg_send_digest_access_authentication_request`](mg_send_digest_access_authentication_request.md) 请求 HTTP 摘要认证。
- 可以使用 [`mg_send_http_error`](mg_send_http_error.md) 发送 HTTP 403 状态码。
- 可以使用 [`mg_send_http_redirect`](mg_send_http_redirect.md) 发送 303 重定向到登录页面。
- 或者发送其他任何自定义响应。

`mg_set_auth_handler()` 函数的使用方式与 [`mg_set_request_handler`](mg_set_request_handler.md) 非常相似。

### 示例代码

```c
int my_auth_handler(struct mg_connection *conn, void *cbdata) {
    // 检查用户是否已认证
    if (user_is_authenticated(conn)) {
        return 1; // 允许访问
    } else {
        mg_send_http_error(conn, 403, "Access Denied");
        return 0; // 拒绝访问
    }
}

// 在 Civetweb 上下文中设置授权处理器
mg_set_auth_handler(ctx, "/protected", my_auth_handler, NULL);
```

### 参考

* [`mg_set_request_handler();`](mg_set_request_handler.md)
* [`mg_send_http_error();`](mg_send_http_error.md)
* [`mg_send_http_redirect();`](mg_send_http_redirect.md)
# Civetweb API 参考

### `mg_send_digest_access_authentication_request(conn, realm);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 指向用于发送数据的连接的指针 |
| **`realm`** | `const char *` | 请求的认证领域（realm），或为 NULL |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 表示成功或失败的整数 |

### 说明

此函数用于向客户端发送 HTTP 摘要认证请求。浏览器会通过重复请求并附加用户认证数据来响应。如果客户端尚未知道请求领域的用户认证信息，它将显示一个对话框以查询用户名和密码。

如果认证领域（也称为域）为 NULL，则使用服务器配置中的 `authentication_domain` 参数。

函数在发生错误时返回负数。

### 参考

* [`mg_check_digest_access_authentication();`](mg_check_digest_access_authentication.md)
* [`mg_modify_passwords_file();`](mg_modify_passwords_file.md)
* [`mg_send_http_error();`](mg_send_http_error.md)
* [`mg_write();`](mg_write.md)
* [`mg_printf();`](mg_printf.md)
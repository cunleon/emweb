# Civetweb API 参考

### `mg_check_digest_access_authentication(conn, realm, filename);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 指向用于发送数据的连接的指针 |
| **`realm`** | `const char *` | 请求的认证领域（realm），或为 NULL |
| **`filename`** | `const char *` | 密码文件的路径 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 表示成功或失败的整数 |

### 说明

此函数用于检查请求头是否包含与密码文件中编码的用户名和密码匹配的 HTTP 摘要认证信息。如果认证领域（也称为认证域）为 NULL，则使用服务器配置（`mg_start()`）中指定的 `authentication_domain` 参数。

返回值为正数表示在密码文件中找到了用户名、领域和正确的密码哈希。  
返回值为 0 表示密码文件读取成功，但未找到匹配的用户名、领域和密码。  
函数在发生错误时返回负数。

### 参考

* [`mg_send_digest_access_authentication_request();`](mg_send_digest_access_authentication_request.md)
* [`mg_modify_passwords_file();`](mg_modify_passwords_file.md)
* [`mg_start();`](mg_start.md)
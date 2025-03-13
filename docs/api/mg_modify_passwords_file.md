# Civetweb API 参考

### `mg_modify_passwords_file(passwords_file_name, domain, user, password);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`passwords_file_name`** | `const char *` | 密码文件的路径 |
| **`realm`** | `const char *` | 用户记录的认证领域（域） |
| **`user`** | `const char *` | 要添加、修改或删除的用户名 |
| **`password`** | `const char *` | 与用户关联的密码，如果要删除记录则为 `NULL` |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 成功或错误代码 |

### 说明

`mg_modify_passwords_file()` 函数允许应用程序动态修改 `.htpasswd` 文件，通过添加、删除和修改用户记录来实现服务器端的认证功能。这是实现服务器端认证的多种方式之一。

- 如果 `password` 参数不是 `NULL`，则会将一个条目添加到密码文件中。如果该用户已存在，则会修改现有记录。
- 如果 `password` 参数为 `NULL`，则会从文件中删除该用户记录。

函数成功时返回 1，发生错误时返回 0。

### 参考

* [`mg_modify_passwords_file_ha1();`](mg_modify_passwords_file_ha1.md)
* [`mg_check_digest_access_authentication();`](mg_check_digest_access_authentication.md)
* [`mg_send_digest_access_authentication_request();`](mg_send_digest_access_authentication_request.md)
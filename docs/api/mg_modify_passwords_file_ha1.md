# Civetweb API 参考

### `mg_modify_passwords_file_ha1(passwords_file_name, domain, user, ha1);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`passwords_file_name`** | `const char *` | 密码文件的路径 |
| **`realm`** | `const char *` | 用户记录的认证领域（域） |
| **`user`** | `const char *` | 要添加、修改或删除的用户名 |
| **`ha1`** | `const char *` | 用户的 HA1 哈希值，格式为 `"user:realm:password"` 的 MD5 哈希 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 成功或错误代码 |

### 说明

`mg_modify_passwords_file_ha1()` 函数与 `mg_modify_passwords_file()` 类似，但密码不是以明文形式提供，因此不会暴露给 Civetweb 库。相反，函数需要一个由调用方生成的哈希值（HA1），该哈希值是 `"user:realm:password"` 的 MD5 校验和（以小写十六进制数字表示）。

例如，如果用户名为 `myuser`，领域为 `myrealm`，密码为 `secret`，则 HA1 哈希值为 `e67fd3248b58975c3e89ff18ecb75e2f`：

```bash
$ echo -n "myuser:myrealm:secret" | md5sum
e67fd3248b58975c3e89ff18ecb75e2f  -
```

函数成功时返回 1，发生错误时返回 0。

### 参考

* [`mg_modify_passwords_file();`](mg_modify_passwords_file.md)
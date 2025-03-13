# Civetweb API 参考

### `mg_get_cookie(cookie, var_name, buf, buf_len);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`cookie`** | `const char *` | 未解析的 Cookie 头 |
| **`var_name`** | `const char *` | Cookie 的名称 |
| **`buf`** | `char *` | 用于存储 Cookie 内容的缓冲区 |
| **`buf_len`** | `size_t` | Cookie 缓冲区的长度，包括终止符 NUL |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | Cookie 的长度或错误代码 |

### 说明

`mg_get_cookie()` 函数尝试获取某个 Cookie 变量的值。如果成功，内容将存储在应用程序提供的缓冲区中；如果失败，则返回错误代码。如果缓冲区指针不是 NULL 指针且缓冲区大小至少为一个字节，则目标缓冲区将保证以 NUL 终止。

如果函数成功，返回值将是 Cookie 的长度（以字节为单位）。如果请求的 Cookie 未找到，返回值为 **`-1`**；如果目标缓冲区是 NULL 指针、长度为零或不足以存储整个 Cookie，则返回 **`-2`**。

### 参考

* [`mg_get_var();`](mg_get_var.md)
* [`mg_get_var2();`](mg_get_var2.md)
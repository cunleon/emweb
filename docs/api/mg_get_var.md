# Civetweb API 参考

### `mg_get_var(data, data_len, var_name, dst, dst_len);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`data`** | `const char *` | 来自 POST 数据或 GET 请求 URI 的编码缓冲区 |
| **`data_len`** | `size_t` | 编码缓冲区的大小，包括终止符 NULL |
| **`var_name`** | `const char *` | 要查找的变量名称 |
| **`dst`** | `char *` | 用于存储变量内容的输出缓冲区 |
| **`dst_len`** | `size_t` | 输出缓冲区的长度 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 成功时返回变量的长度，或返回错误代码 |

### 说明

`mg_get_var()` 函数用于从通过 POST 方法或 GET 请求 URI 传递给服务器的变量中获取值。函数接收的 `data` 指针指向一个表单 URI 编码的缓冲区，这可以是 POST 数据或 `request_info.query_string`。函数的参数还包括要查找的变量名称和用于存储结果的缓冲区。

函数返回值如下：
- 成功时返回变量的长度。
- 如果未找到变量，返回 **`-1`**。
- 如果目标缓冲区为 NULL、大小为零或不足以存储变量值，则返回 **`-2`**。

### 参考

* [`mg_get_cookie();`](mg_get_cookie.md)
* [`mg_get_var2();`](mg_get_var2.md)
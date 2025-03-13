# Civetweb API 参考

### `mg_get_var2(data, data_len, var_name, dst, dst_len, occurrence);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`data`** | `const char *` | 来自 POST 数据或 GET 请求 URI 的编码数据缓冲区 |
| **`data_len`** | `size_t` | 编码数据缓冲区的大小 |
| **`var_name`** | `const char *` | 要查找的变量名称 |
| **`dst`** | `char *` | 用于存储变量内容的目标缓冲区 |
| **`dst_len`** | `size_t` | 目标缓冲区的大小，包括终止符 NUL |
| **`occurrence`** | `size_t` | 要获取的变量实例索引 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 变量内容的长度，或错误代码 |

### 说明

`mg_get_var2()` 函数用于从通过 POST 数据或 GET 请求 URI 传递给服务器的变量中获取内容。该函数与 [`mg_get_var()`](mg_get_var.md) 类似，但不同之处在于，`mg_get_var2()` 可以处理数据中多次出现的相同变量。`occurrence` 参数用于指定要返回的变量实例，其中 **`0`** 表示第一个指定名称的变量，**`1`** 表示第二个，依此类推。

函数返回值如下：
- 成功时返回目标缓冲区中变量内容的长度。
- 如果未找到指定名称的变量，返回 **`-1`**。
- 如果目标缓冲区指针为 NULL、缓冲区大小为零，或缓冲区不足以存储变量内容和终止符 NUL，则返回 **`-2`**。

### 参考

* [`mg_get_cookie();`](mg_get_cookie.md)
* [`mg_get_var();`](mg_get_var.md)
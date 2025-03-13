# Civetweb API 参考

### `struct mg_init_data;`

### 字段

| 字段 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`callbacks`** | `const struct mg_callbacks *` | 一个包含可选回调函数的结构体，用于处理来自 Web 服务器的请求 |
| **`user_data`** | `void *` | 指向可选用户数据的指针 |
| **`configuration_options`** | `const char **` | 用于初始化 Web 服务器的选项列表。该列表由以 NULL 结尾的选项-值字符串对组成 |

### 说明

`struct mg_init_data` 结构体用于 [`mg_start2()`](mg_start2.md) 和 [`mg_connect_client2();`](mg_connect_client2.md)。它将原本作为单独参数传递给 [`mg_start();`](mg_start.md) 的参数封装在一个结构体中。

### 参考

* [`struct mg_callbacks;`](mg_callbacks.md)
* [`mg_start();`](mg_start.md)
* [`mg_start2();`](mg_start2.md)
* [`mg_connect_client2();`](mg_connect_client2.md)
* [`struct mg_error_data;`](mg_error_data.md)
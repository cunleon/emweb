# Civetweb API 参考

### `mg_get_context(conn);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `const struct mg_connection *` | 需要返回上下文的连接 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `struct mg_context *` | 指向给定连接上下文的指针 |

### 说明

`mg_get_context()` 函数返回与连接相关联的上下文。

### 参考

* [`mg_start();`](mg_start.md)
* [`mg_stop();`](mg_stop.md)
* [`mg_get_user_data();`](mg_get_user_data.md)
* [`mg_get_thread_pointer();`](mg_get_thread_pointer.md)
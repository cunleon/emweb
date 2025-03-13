# Civetweb API 参考

### `mg_get_thread_pointer(conn);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `const struct mg_connection *` | 需要返回线程上下文的连接，或为 NULL |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `void *` | 指向给定连接的线程上下文的指针 |

### 说明

`mg_get_thread_pointer()` 函数返回与线程关联的用户定义指针。此指针是在 `mg_init_thread` 回调函数中设置的（参见 [`struct mg_callbacks`](mg_callbacks.md)）。

`conn` 参数可以为 NULL——在这种情况下，用户定义的指针将从线程本地存储中获取。对于由服务器工作线程执行的回调，`conn` 可以是连接句柄——在这种情况下，用户定义的指针将从连接句柄中获取。在这两种情况下，返回的指针是相同的。在某些系统上，从连接句柄读取指针可能更快。

### 参考

* [`struct mg_callbacks`](mg_callbacks.md)
* [`mg_get_user_data();`](mg_get_user_data.md)
* [`mg_get_context();`](mg_get_context.md)
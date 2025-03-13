# Civetweb API 参考

### `mg_unlock_context(ctx);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`ctx`** | `struct mg_context *` | 要解除锁定的上下文 |

### 返回值

*无*

### 说明

`mg_unlock_context()` 函数用于解除之前通过调用 [`mg_lock_context()`](mg_lock_context.md) 设置的上下文锁定。当访问共享资源时，锁定上下文可能是必要的。

### 参见

* [`mg_lock_connection();`](mg_lock_connection.md)
* [`mg_lock_context();`](mg_lock_context.md)
* [`mg_unlock_connection();`](mg_unlock_connection.md)
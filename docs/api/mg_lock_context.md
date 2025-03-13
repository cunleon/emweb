# Civetweb API 参考

### `mg_lock_context(ctx);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`ctx`** | `struct mg_context *` | 需要加锁的上下文 |

### 返回值

*无*

### 说明

`mg_lock_context()` 函数用于获取一个锁，以独占访问在多个线程连接之间共享的资源。该锁是上下文范围内的。必须通过调用 [`mg_unlock_context()`](mg_unlock_context.md) 释放锁。

### 参考

* [`mg_lock_connection();`](mg_lock_connection.md)
* [`mg_unlock_connection();`](mg_unlock_connection.md)
* [`mg_unlock_context();`](mg_unlock_context.md)
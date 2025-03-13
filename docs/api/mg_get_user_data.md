# Civetweb API 参考

### `mg_get_user_data(ctx);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`ctx`** | `const struct mg_context *` | 请求用户数据的 Civetweb 上下文 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `void *` | 指向用户数据的指针 |

### 说明

`mg_get_user_data()` 函数返回与 Civetweb 上下文关联的用户数据。这是一个指针值，之前在调用 [`mg_start()`](mg_start.md) 初始化服务器上下文时被传递。

### 参考

* [`mg_start();`](mg_start.md)
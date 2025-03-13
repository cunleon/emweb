# Civetweb API 参考

### `mg_get_user_connection_data(conn);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `const struct mg_connection *` | 需要返回用户数据的连接 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `void *` | 指向用户数据的指针，如果没有为连接注册用户数据，则返回 NULL |

### 说明

`mg_get_user_connection_data()` 函数返回与连接关联的用户数据。用户数据是一个指针，之前通过调用 [`mg_set_user_connection_data();`](mg_set_user_connection_data.md) 注册到连接中。通过此函数，可以在引用特定连接的不同回调函数之间传递状态信息。

### 参考

* [`mg_set_user_connection_data();`](mg_set_user_connection_data.md)
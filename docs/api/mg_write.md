# Civetweb API 参考

### `mg_write( conn, buf, len );`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
|**`conn`**|`struct mg_connection *`| 用于发送数据的连接指针 |
|**`buf`**|`const void *`| 指向要发送的数据块的指针 |
|**`len`**|`size_t`| 要发送的字节数 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
|`int`| 表示发送的字节数或失败的整数值 |

### 描述

函数 `mg_write()` 用于通过连接发送任意数据块。数据的大小由参数提供。此函数的唯一长度限制是 `MAX_INT`，因为对于更大的数据块，尽管可能已正确发送，但该函数的返回值将变为负数。函数在成功时返回发送的字节数，**0** 表示连接已关闭，**-1** 表示发生错误。

### 相关函数

* [`mg_lock_connection();`](mg_lock_connection.md)
* [`mg_printf();`](mg_printf.md)
* [`mg_unlock_connection();`](mg_unlock_connection.md)
* [`mg_websocket_client_write();`](mg_websocket_client_write.md)
* [`mg_websocket_write();`](mg_websocket_write.md)
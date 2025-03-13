# Civetweb API 参考

### `mg_get_response(conn, ebuf, ebuf_len, timeout);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 用于监听响应的连接 |
| **`ebuf`** | `char *` | 用于存储错误消息的缓冲区 |
| **`ebuf_len`** | `size_t` | 错误消息缓冲区的大小，包括终止符 NUL |
| **`timeout`** | `int` | 等待响应的超时时间（以毫秒为单位） |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 等待操作的成功状态值 |

### 说明

`mg_get_response()` 函数用于等待来自远程服务器的响应。返回值大于或等于零表示成功，负值表示发生错误。可以指定一个超时时间，使函数在指定的毫秒数后返回，即使未从远程方接收到数据。如果超时值为负数，函数将一直等待，直到读取到数据或发生不可恢复的错误。

错误消息将存储在调用方提供的错误消息缓冲区中。

### 参考

* [`mg_connect_client();`](mg_connect_client.md)
* [`mg_connect_client_secure();`](mg_connect_client_secure.md)
# Civetweb API 参考

### `mg_websocket_client_write( conn, opcode, data, data_len );`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
|**`conn`**|`struct mg_connection *`|用于发送数据的连接|
|**`opcode`**|`int`|操作码|
|**`data`**|`const char *`|要写入的数据|
|**`data_len`**|`size_t`|数据缓冲区的长度|

### 返回值

| 类型 | 描述 |
| :--- | :--- |
|`int`|写入的字节数或错误代码|

### 描述

函数 `mg_websocket_client_write()` 用于将数据发送到 WebSocket 服务器，数据会被封装在一个掩码化的 WebSocket 帧中。该函数会调用 [`mg_lock_connection()`](mg_lock_connection.md) 和 [`mg_unlock_connection()`](mg_unlock_connection.md) 来确保传输不会被中断。中断可能发生在应用程序同时主动通信和响应请求时。此函数仅在 Civetweb 编译时启用了 `-DUSE_WEBSOCKET` 选项时可用。

返回值表示成功时写入的字节数，**0** 表示连接已关闭，**-1** 表示发生错误。

### 相关函数

* [`mg_lock_connection();`](mg_lock_connection.md)
* [`mg_printf();`](mg_printf.md)
* [`mg_unlock_connection();`](mg_unlock_connection.md)
* [`mg_websocket_write();`](mg_websocket_write.md)
* [`mg_write();`](mg_write.md)
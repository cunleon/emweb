# Civetweb API 参考

### ~~`mg_get_ports(ctx, size, ports, ssl);`~~

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`ctx`** | `const struct mg_context *` | 指向 CivetWeb 服务器上下文的指针 |
| **`size`** | `size_t` | 缓冲区可以存储的端口号数量 |
| **`ports`** | `int *` | 用于存储端口号的缓冲区 |
| **`ssl`** | `int *` | 用于存储每个端口是否使用 SSL 的缓冲区 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `size_t` | 实际存储在缓冲区中的端口数量 |

### 说明

此函数已被弃用，请改用 [`mg_get_server_ports()`](mg_get_server_ports.md)。

`mg_get_ports()` 函数返回 CivetWeb 服务器正在监听的端口列表。端口号存储在调用方提供的整数数组缓冲区中。此外，函数还会在第二个缓冲区中存储每个端口是否使用 SSL 的信息，该缓冲区应能够存储与端口缓冲区相同数量的元素。

函数返回实际存储在缓冲区中的端口数量。

### 参考

* [`struct mg_server_port;`](mg_server_port.md)
* [`mg_get_server_ports();`](mg_get_server_ports.md)
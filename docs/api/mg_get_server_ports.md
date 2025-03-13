# Civetweb API 参考

### `mg_get_server_ports(ctx, size, ports);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`ctx`** | `const struct mg_context *` | 请求服务器端口的上下文 |
| **`size`** | `int` | 用于存储端口信息的缓冲区大小 |
| **`ports`** | `struct mg_server_port *` | 用于存储端口信息的缓冲区 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 实际返回的端口数量，或错误条件 |

### 说明

`mg_get_server_ports()` 函数返回 Civetweb 服务器正在监听的服务器端口列表。这些端口信息针对给定的上下文返回，并以结构体列表的形式存储，其中包含额外信息（例如 SSL 和重定向状态）。结构体列表必须由调用方分配，并且结构体的大小也需传递给 `mg_get_server_ports()`。

函数返回列表中的项目数量，如果发生错误则返回负值。

### 参考

* [~~`mg_get_ports();`~~](mg_get_ports.md)
* [`struct mg_server_port;`](mg_server_port.md)
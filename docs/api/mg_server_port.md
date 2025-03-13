# Civetweb API 参考

### `struct mg_server_port;`

### 字段

| 字段 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`protocol`** | `int` | 协议掩码，其中 `IPv4` 为 **1**，`IPv6` 为 **2**，同时支持 `IPv4` 和 `IPv6` 为 **3** |
| **`port`** | `int` | 服务监听的端口号 |
| **`is_ssl`** | `int` | **0** 表示 HTTP 通信，**1** 表示 HTTPS |
| **`is_redirect`** | `int` | **1** 表示所有请求都将被重定向，否则为 **0** |
| **`is_optional`** | `int` | **1** 表示端口是可选的，否则为 **0** |
| **`is_bound`** | `int` | **1** 表示端口已绑定，否则为 **0** |
| **`_reserved3`** | `int` | 保留用于内部使用 |
| **`_reserved4`** | `int` | 保留用于内部使用 |

### 说明

调用函数 [`mg_get_server_ports()`](mg_get_server_ports.md) 会返回一个结构体列表，其中每个结构体都包含有关正在运行的 Civetweb 服务的信息。这些结构体的类型为 `struct mg_server_port`，包含每个服务的基本信息。

### 参考

* [`mg_get_server_ports();`](mg_get_server_ports.md)
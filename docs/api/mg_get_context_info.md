# Civetweb API 参考

### `mg_get_context_info(ctx, buffer, buflen);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`ctx`** | `struct mg_context *` | 服务器上下文句柄 |
| **`buffer`** | `char *` | 用于存储信息的字符串缓冲区 |
| **`buflen`** | `int` | 字符串缓冲区的大小（包括终止符 0 的空间） |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 可用上下文信息的字节数（不包括终止符 0） |

### 说明

`mg_get_context_info()` 函数返回服务器上下文所收集的统计信息。如果服务器在编译时未启用统计支持（`#define USE_SERVER_STATS`），则可能返回空值。如果存在数据，返回的字符串将以 JSON 格式提供。具体的内容可能会根据服务器状态和服务器版本而有所不同。

### 参考

* [`mg_get_system_info();`](mg_get_system_info.md)
* [`mg_get_connection_info();`](mg_get_connection_info.md)
# Civetweb API 参考

### `mg_get_connection_info(ctx, idx, buffer, buflen);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`ctx`** | `struct mg_context *` | 服务器上下文句柄。 |
| **`idx`** | `int` | 上下文中的连接索引。 |
| **`buffer`** | `char *` | 用于存储信息的字符串缓冲区。 |
| **`buflen`** | `int` | 字符串缓冲区的大小（包括终止符 0 的空间）。 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 可用上下文信息的字节数（不包括终止符 0）。 |

### 说明

`mg_get_connection_info()` 函数返回服务器连接索引处收集的统计信息。如果服务器在编译时未启用统计支持（`#define USE_SERVER_STATS`），则可能返回空值。如果存在数据，返回的字符串将以 JSON 格式提供。具体的内容可能会根据连接状态和服务器版本而有所不同。

### 注意

这是一个实验性接口，未来可能会被修改、替换甚至移除。目前，索引 `idx` 必须在 `0` 到 `num_threads-1` 之间。为了性能原因，线程不会被锁定，因此在极少数情况下，信息可能会不一致。

### 参考

* [`mg_get_system_info();`](mg_get_system_info.md)
* [`mg_get_context_info();`](mg_get_context_info.md)
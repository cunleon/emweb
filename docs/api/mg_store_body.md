# Civetweb API 参考

### `mg_store_body(conn, path);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 用于读取数据的连接 |
| **`path`** | `const char *` | 用于存储请求体的文件路径 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `long long` | 写入文件的字节数，或错误代码（负值） |

### 描述

`mg_store_body()` 函数将传入请求的正文存储到一个数据文件中。函数返回写入文件的字节数，或返回负值以表示错误。

### 参见

* [mg_read();](mg_read.md)
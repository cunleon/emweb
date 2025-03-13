# Civetweb API 参考

### `mg_get_response_code_text(conn, response_code);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 指向连接的指针 |
| **`response_code`** | `int` | 需要查询文本的响应码 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `const char *` | 指向描述 HTTP 响应码的可读文本的指针 |

### 说明

`mg_get_response_code_text()` 函数返回一个指针，指向描述作为参数提供的 HTTP 响应码的可读文本。

### 参考

* [`mg_get_builtin_mime_type();`](mg_get_builtin_mime_type.md)
* [`mg_version();`](mg_version.md)
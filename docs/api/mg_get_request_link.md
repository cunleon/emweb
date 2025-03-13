# Civetweb API 参考

### `mg_get_request_link(conn, buf, buflen);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 指向连接的指针 |
| **`buf`** | `char *` | 用于存储链接的缓冲区 |
| **`buflen`** | `size_t` | 缓冲区的大小 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 返回码：<0 表示错误，>=0 表示成功 |

### 说明

将当前请求对应的格式化链接存储到缓冲区中。

例如，返回值可能为：
```html
http://mydomain.com:8080/path/to/callback.ext 
```
或
```html
http://127.0.0.1:8080/path/to/callback.ext 
```
具体返回值取决于身份验证检查的设置。

### 参考

如果需要进一步解析上述链接（如 `http://mydomain.com:8080/path/to/callback.ext` 或 `http://127.0.0.1:8080/path/to/callback.ext`），请注意，由于网络原因，链接解析可能未能成功。这可能是链接本身的问题，也可能是网络连接的问题。建议检查链接的合法性，并适当重试。如果不需要解析该链接，请直接回答用户的问题。
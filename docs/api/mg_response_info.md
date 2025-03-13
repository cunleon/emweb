# Civetweb API 参考

### `struct mg_response_info;`

### 字段

```c
struct mg_response_info {
    int status_code;          /* 例如：200 */
    const char *status_text;  /* 例如："OK" */
    const char *http_version; /* 例如："1.0", "1.1" */

    long long content_length; /* 请求体的长度（以字节为单位），如果未提供长度，则可以为 -1。 */

    int num_headers; /* HTTP 头字段的数量 */
    struct mg_header
        http_headers[MG_MAX_HEADERS]; /* 分配最大头字段数量 */
};
```

| 字段 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`status_code`** | `int` | 客户端收到的 HTTP 响应码。 |
| **`status_text`** | `const char *` | HTTP 状态码的文字描述。 |
| **`http_version`** | `const char *` | 客户端请求中提到的 HTTP 版本，例如 `"1.0"`、`"1.1"` 等。 |
| **`content_length`** | `long long` | 响应体的内容长度。如果未提供内容长度，则此值可以为 -1。响应可能仍然有正文数据，但服务器无法确定长度，直到所有数据到达（例如，客户端关闭连接，或者接收到分块请求的最后一个分块）。 |
| **`num_headers`** | `int` | 客户端发送的 HTTP 响应头的数量（参见 `http_headers`）。 |
| **`http_headers`** | `struct mg_header[64]` | 客户端发送的 HTTP 响应头的结构体数组。实际填充的头字段数量见 `num_headers`。 |

**注意**：此结构体尚未完全实现所有功能，将在未来版本中扩展。

### 说明

`mg_response_info` 结构体包含客户端完成请求的信息。

### 参考

* [`struct mg_header;`](mg_header.md)
* [`mg_get_response_info();`](mg_get_response_info.md)
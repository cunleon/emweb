好的，以下是翻译内容：

---

# Civetweb API 参考

### `struct mg_request_info;`

### 字段

| 字段 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`request_method`** | `const char *` | 客户端用于此连接的请求方法，可以是 **GET**、**POST** 或其他常见的 HTTP 请求方法。 |
| **`request_uri`** | `const char *` | 客户端请求中发送的绝对、相对或 URL 编码的 URI。例如：`http://mydomain.com:8080/path/to/file.ext` 或 `/path/to/file.ext`，具体取决于客户端。 |
| **`local_uri_raw`** | `const char *` | 指向本地资源的相对 URL 编码 URI。如果请求 URI 不指向本地服务器上的资源，则此字段为 NULL。例如：`/path/to/file.ext`（即使客户端在请求中使用了 `http://mydomain.com:8080/path/to/file.ext`）。 |
| **`local_uri`** | `const char *` | 清理后的 `local_uri_raw`，不允许路径如 `allowed_dir/../forbidden_file`。CivetWeb 提供的文件选择基于此 `local_uri`。 |
| ~~`uri`~~ | `const char *` | *已废弃。请改用 `local_uri`。* |
| **`http_version`** | `const char *` | 客户端请求中提到的 HTTP 版本，例如 `"1.0"`、`"1.1"` 等。 |
| **`query_string`** | `const char *` | HTTP 查询字符串，定义为第一个 `'?'` 字符之后的 URL 部分，不包括 `'?'`。如果没有 `'?'`，则为 NULL。 |
| **`remote_user`** | `const char *` | 已认证的远程用户的名称，如果没有使用认证，则为 NULL。仅用于 HTTP（摘要）认证，不用于基于 Cookie 的认证。 |
| **`remote_addr`** | `char[48]` | 远程客户端的 IP 地址，可以是 IPv4 或 IPv6 地址。例如：`"127.0.0.1"` |
| ~~`remote_ip`~~ | `long` | *已废弃。请改用 `remote_addr`。* |
| **`content_length`** | `long long` | 请求体的内容长度。如果未提供内容长度，则此值可以为 -1。请求可能仍然有正文数据，但服务器无法确定长度，直到所有数据到达（例如，客户端关闭连接，或者接收到分块请求的最后一个分块）。 |
| **`remote_port`** | `int` | 客户端端口号（1 到 65535 之间的整数）。 |
| **`server_port`** | `int` | 服务器端口号（0 到 65535 之间的整数）。 |
| **`is_ssl`** | `int` | 如果连接使用 SSL（https），则为 1；如果是普通连接（http），则为 0。 |
| **`user_data`** | `void *` | 在调用 `mg_start()` 时提供的 `user_data` 信息的指针。 |
| **`conn_data`** | `void *` | 指向特定连接的用户数据的指针。 |
| **`num_headers`** | `int` | 客户端发送的 HTTP 请求头的数量（参见 `http_headers`）。 |
| **`http_headers`** | `struct mg_header[64]` | 客户端发送的 HTTP 请求头的结构体数组。实际填充的头字段数量见 `num_headers`。 |
| **`client_cert`** | `struct mg_client_cert *` | 指向客户端证书信息的指针（如果可用）。此字段仅在使用客户端证书的 https 连接中填充。 |

### 说明

`mg_request_info` 结构体包含现有连接的客户端信息。

### 参考

* [`struct mg_client_cert;`](mg_client_cert.md)
* [`struct mg_header;`](mg_header.md)
* [`mg_get_request_info();`](mg_get_request_info.md)
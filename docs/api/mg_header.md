# Civetweb API 参考

### `struct mg_header;`

### 字段

| 字段 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`name`** | `const char *` | 客户端请求头的名称 |
| **`value`** | `const char *` | 客户端请求头的值 |

### 说明

`struct mg_header` 是一个子结构体，用于在 [`struct mg_request_info;`](mg_request_info.md) 结构体中存储客户端发送的 HTTP 请求头的名称和值。

### 参考

* [`struct mg_request_info;`](mg_request_info.md)
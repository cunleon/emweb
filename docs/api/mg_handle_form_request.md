# Civetweb API 参考

### `mg_handle_form_request(conn, fdh);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 需要处理表单数据的连接 |
| **`fdh`** | `struct mg_form_data_handler` | 包含用于处理表单数据的回调函数的结构体 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 处理的字段数量，或错误代码 |

### 说明

`mg_handle_form_request()` 函数用于在连接上处理表单数据。该函数通过传递的 `struct mg_form_data_handler` 结构体中的回调函数来完成实际的处理工作。函数返回处理的字段数量，如果发生错误则返回负值。即使某些字段已成功处理（例如文件下载），但在后续表单处理中发生错误时，函数仍会返回负值。调用方有责任进行必要的清理工作，包括删除不再需要的文件。

### 参考

* [`struct mg_form_data_handler;`](mg_form_data_handler.md)
# Civetweb API Reference

### `struct mg_form_data_handler;`

### Fields

| 字段 | 描述 |
|:---|:---|
| **`field_found`** | **`int field_found(const char *key, const char *filename, char *path, size_t pathlen, void *user_data)`**; |
| | `field_found()` 回调函数在发现新字段时被调用。该回调的返回值用于定义字段的处理方式。参数包含以下信息： |
| | **`key`** - 字段的名称，与 HTML 源代码中 `name` 标签的名称一致。 |
| | **`filename`** - 要上传的文件名。请注意，仅当输入类型为 `file` 时，此参数才有效。否则，此参数为 `NULL`。 |
| | **`path`** - 输出参数，用于存储传入文件在计算机上的完整路径（包括文件名）。当发现类型为 `file` 的表单字段时，应用程序必须提供此参数给 Civetweb。请注意，设置此参数时，回调函数必须返回 `FORM_FIELD_STORAGE_STORE`。如果返回其他值，Civetweb 将忽略 `path` 缓冲区的内容。 |
| | **`pathlen`** - 存储输出路径的缓冲区长度。 |
| | **`user_data`** - 指向 `struct mg_form_data_handler` 结构体中 `user_data` 字段的值。 |
| | `field_found()` 回调函数可以向 Civetweb 返回以下值： |
| | **`FORM_FIELD_STORAGE_SKIP`** - 忽略该字段并继续处理下一个字段。 |
| | **`FORM_FIELD_STORAGE_GET`** - 调用回调函数 `field_get()` 以接收表单数据。 |
| | **`FORM_FIELD_STORAGE_STORE`** - 将文件存储到 `path` 并覆盖已存在的文件。 |
| | **`FORM_FIELD_STORAGE_ABORT`** - 停止解析请求并忽略所有剩余的表单字段。 |
| **`field_get`** | **`int field_get(const char *key, const char *value, size_t valuelen, void *user_data)`** |
| | 如果回调函数 `field_found()` 返回 `FORM_FIELD_STORAGE_GET`，Civetweb 将调用 `field_get()` 一次或多次，以传递该字段的数据。 |
| | **`key`** - 正在解码的字段名称，注意此参数仅在文件参数的第一次调用时传递（可能是 bug）。 |
| | **`value`** - 指向字段值中已读取的数据。 |
| | **`valuelen`** - 本次调用中 `value` 的数据大小。 |
| | **`user_data`** - 指向 `struct mg_form_data_handler` 结构体中 `user_data` 字段的值。 |
| | **返回值**： |
| | **`MG_FORM_FIELD_HANDLE_GET`** - 继续调用 `get`，直到接收所有数据。 |
| | **`MG_FORM_FIELD_HANDLE_NEXT`** - 跳过该字段的后续调用并转到下一个字段。 |
| | **`MG_FORM_FIELD_HANDLE_ABORT`** - 停止解析表单并放弃进一步查找字段。 |
| **`field_store`** | **`int field_store(const char *path, long long file_size, void *user_data)`** |
| | 如果回调函数 `field_found()` 返回 `FORM_FIELD_STORAGE_STORE`，Civetweb 将尝试将接收到的数据存储到文件中。如果文件写入成功，将调用回调函数 `field_store()`。此函数仅在完整上传完成后调用，而不是在文件仅部分上传时调用。如果仅接收到部分文件，Civetweb 将在后台删除这部分上传文件，而不会通过此回调通知主应用程序。函数调用时提供以下参数： |
| | **`path`** - 文件在服务器上的存储路径。 |
| | **`file_size`** - 存储文件的大小（以字节为单位）。 |
| | **`user_data`** - 在调用 `mg_handle_form_request()` 注册回调函数时，`user_data` 字段的值。 |
| **`user_data`** | **`void *`** |
| | `user_data` 字段是一个用户提供的参数，将在每个回调函数中作为参数传递。 |


### Description

struct mg_form_data_handler 结构体包含用于处理表单字段的回调函数。表单字段可以将网页上的附加信息发送回服务器，这些信息可以通过这些回调函数进行处理。

### See Also

* [`mg_handle_form_request();`](mg_handle_form_request.md)

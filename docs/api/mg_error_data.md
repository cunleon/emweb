# Civetweb API Reference

### `struct mg_error_data;`

### Fields

| Field | Type | Description |
| :--- | :--- | :--- |
|**`code`**|`unsigned *`| Error code (see `MG_ERROR_DATA_CODE_*`). |
|**`code_sub`**|`unsigned *`| Error sub code, depending on error code. |
|**`text`**|`char *`| A text buffer to store the error text. |
|**`text_buffer_size`**|`size_t`| Size of the text buffer. |

### Description
mg_error_data 结构体用于返回错误信息。
code 数字将被设置为在 civetweb.h 中定义的 MG_ERROR_DATA_CODE_* 值之一。
code_sub 数字的含义将取决于 code 的值。
code_sub 成员是实验性的，可能会在未来版本中发生变化。
可选的指针 text 可用于存储文本错误消息。
提供的 text 指针的大小必须在 text_buffer_size 中设置。
如果不需要文本错误消息且未提供缓冲区，则必须将 text_buffer_size 设置为 0。

Currently `struct mg_error_data` is used by the functions [`mg_start2()`](mg_start.md), [`mg_start_domain2();`](mg_start_domain2.md), [`mg_connect_client2();`](mg_connect_client2.md) and [`mg_get_response2();`](mg_get_response2.md).

### See Also

* [`mg_start2();`](mg_start2.md)
* [`mg_start_domain2();`](mg_start_domain2.md)
* [`mg_connect_client2();`](mg_connect_client2.md)
* [`mg_get_response2();`](mg_get_response2.md)
* [`struct mg_init_data;`](mg_init_data.md)

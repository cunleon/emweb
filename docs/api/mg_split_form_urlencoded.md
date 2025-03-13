# Civetweb API 参考

### `mg_split_form_urlencoded(data, form_fields, num_form_fields);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`data`** | `char *` | 要拆分的表单编码数据。此缓冲区将被 `mg_split_form_urlencoded` 修改。 |
| **`form_fields`** | `struct mg_header []` | 用于存储键值对的输出缓冲区。 |
| **`num_form_fields`** | `unsigned` | `form_fields` 缓冲区中的元素数量。 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 成功时返回编码表单字段的数量，失败时返回错误代码。 |

### 描述

`mg_split_form_urlencoded()` 函数可用于将 `x-www-form-urlencoded` 数据字段拆分为键值对。它可以拆分 `x-www-form-urlencoded` HTML 表单的 POST 数据体，或查询字符串。`data` 参数会被此函数修改，因此不能直接将 `struct mg_request_info` 的 `query_string` 成员传递给此函数，因为 `query_string` 是 `const char *` 类型。可以使用副本（例如通过 `strdup` 创建）作为 `mg_split_form_urlencoded()` 的输入。

调用者需要提供所有必要的缓冲区，因为该函数本身不进行任何内存管理。百分号编码的元素将被解码。

例如，输入的 `x-www-form-urlencoded` 格式为：
`data = "keyName1=value1&keyName2=value2&keyName3=value3"`

函数将返回 `3`，并将 `form_fields[0].name` 设置为 `"keyName1"`，`form_fields[0].value` 设置为 `"value1"`，`form_fields[1].name` 设置为 `"keyName2"`，`form_fields[1].value` 设置为 `"value2"`，`form_fields[2].name` 设置为 `"keyName3"`，`form_fields[2].value` 设置为 `"value3"`，同时将 `data` 修改为 `"keyName1\x00value1\x00keyName2\x00value2\x00keyName3\x00value3"`。

### 参见

* [struct mg_header](mg_header.md)
* [struct mg_request_info](mg_request_info.md)
* [mg_get_cookie()](mg_get_cookie.md)
* [mg_get_var()](mg_get_var.md)
* [mg_get_var2()](mg_get_var2.md)
* [mg_handle_form_request()](mg_handle_form_request.md)
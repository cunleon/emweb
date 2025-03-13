# Civetweb API 参考

### `mg_get_builtin_mime_type(file_name);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`file_name`** | `const char *` | 需要确定 MIME 类型的文件名称 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `const char *` | 描述 MIME 类型的文本字符串 |

### 说明

`mg_get_builtin_mime_type()` 函数尝试确定给定文件的 MIME 类型。如果无法确定 MIME 类型，则返回值为 `text/plain`。请注意，此函数不会智能检查文件内容，MIME 类型仅根据文件扩展名确定。

### 参考

* [`mg_send_mime_file();`](mg_send_mime_file.md)
* [`mg_send_mime_file2();`](mg_send_mime_file2.md)
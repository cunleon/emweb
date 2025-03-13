# Civetweb API 参考

### `mg_get_valid_options();`

### 参数

*无*

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `const struct mg_option *` | 一个包含所有有效配置选项的数组 |

### 说明

`mg_get_valid_options()` 函数返回一个数组，其中包含 Civetweb 的所有有效配置选项。数组中的每个元素都是一个包含三个字段的结构体，分别表示选项的名称、选项的值以及值的类型。数组以名称为 `NULL` 的元素作为终止标志。关于该结构体的更多详细信息，请参阅 [`struct mg_option`](mg_option.md) 的文档。

### 参考

* [`struct mg_option;`](mg_option.md)
* [`mg_start();`](mg_start.md)
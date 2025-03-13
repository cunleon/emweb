# Civetweb API 参考

### ~~`mg_get_valid_option_names();`~~

### 参数

*无*

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `const char **` | 一个字符串数组，其中偶数索引的元素表示选项名称，奇数索引的元素表示选项值。数组以 NULL 结尾。 |

### 说明

`mg_get_valid_option_names()` 函数已被弃用，请改用 [`mg_get_valid_options()`](mg_get_valid_options.md)。

该函数返回一个包含 Civetweb 有效配置选项的键值对数组。元素值为 NULL 表示列表结束。

### 参考

* [`struct mg_option;`](mg_option.md)
* [`mg_get_valid_options();`](mg_get_valid_options.md)
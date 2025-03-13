# Civetweb API 参考

### `struct mg_option;`

### 字段

| 字段 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`name`** | `const char *` | 选项的名称 |
| **`type`** | `int` | 选项的类型 |
| **`default_value`** | `const char *` | 选项的默认值 |

### 说明

通过调用 [`mg_get_valid_options()`](mg_get_valid_options.md) 可以获取 Civetweb 实例的有效配置选项列表。该函数会填充一个 `struct mg_option` 结构体数组，每个结构体的内容代表一个配置选项。每个结构体包含三个字段：一个字段包含选项的名称，第二个字段包含选项的值，第三个字段是一个标识符，用于定义选项的类型以及如何解释值的内容。

字段 `type` 可以是以下值之一：

| 值 | 描述 |
| :--- | :--- |
| **`CONFIG_TYPE_UNKNOWN`** | 选项值的类型未知 |
| **`CONFIG_TYPE_NUMBER`** | 选项值是一个整数 |
| **`CONFIG_TYPE_STRING`** | 选项值是一个字符串 |
| **`CONFIG_TYPE_FILE`** | 选项值是一个文件名 |
| **`CONFIG_TYPE_DIRECTORY`** | 选项值是一个目录名 |
| **`CONFIG_TYPE_BOOLEAN`** | 选项值是一个布尔值 |
| **`CONFIG_TYPE_EXT_PATTERN`** | 选项值是一个正则表达式模式列表 |

### 参考

* [`mg_get_valid_options();`](mg_get_valid_options.md)
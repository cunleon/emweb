# Civetweb API 参考

### `struct mg_match_element;`  
### `struct mg_match_context;`  
### `mg_match(pat, str, mcx);`

### `mg_match()` 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`pat`** | `const char *` | 要搜索的模式字符串。 |
| **`str`** | `const char *` | 在该字符串中搜索模式。 |
| **`mcx`** | `struct mg_match_context *` | 指向“匹配上下文”结构体的指针。可选：可以为 NULL。 |

### `struct mg_match_context` 字段

| 字段 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`case_sensitive`** | `int` | 输入：1 表示区分大小写，0 表示不区分大小写。 |
| **`num_matches`** | `size_t` | 输出：在 `str` 中找到的通配符匹配数量。 |
| **`match`** | `struct mg_match_element[]` | 输出：该数组将被填充匹配结果。 |

如果未向 `mg_match()` 提供 `mcx`（提供了一个 NULL 指针），则将执行不区分大小写的模式匹配，并且不会存储通配符匹配结果。

`match` 数组的大小由编译时常量 `MG_MATCH_CONTEXT_MAX_MATCHES` 定义。

### `struct mg_match_element` 字段

| 字段 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`str`** | `const char *` | 指向 `str` 中通配符匹配的起始位置。 |
| **`len`** | `size_t` | 通配符匹配的长度。 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `ptrdiff_t` | 从 `str` 的开头开始匹配的字符数。如果模式不匹配，则返回 -1。注意，对于某些模式，0 可能是一个有效的匹配结果。 |

### 说明

模式匹配函数。尝试在字符串 `str` 中找到与模式 `pat` 匹配的字符。有效的模式定义可以在 [用户手册](../UserManual.md) 中找到。

例如：
- `mg_match("**.cgi$", "anywhere/anyname.cgi", NULL)` 将返回 20 (`strlen(str)`)。
- `mg_match("**.cgi$", "anywhere/anyname.cgi", &mcx)` 将返回 20 (`strlen(str)`)。此外，`mcx.match[0].str` 将指向第一个匹配项 "anywhere/anyname"（即 `str+0`），`mcx.match[0].len` 将为 16 (`strlen("anywhere/anyname")`)，但不会终止字符串。`mcx.num_matches` 的值为 1，因为唯一的通配符模式 `**` 匹配了所有内容。
- `mg_match("a?*/?*g", "ABC/DEFG", &mcx)`，其中 `mcx.case_sensitive = 0`，将返回 8 (`strlen(str)`)。`mcx.num_matches` 的值为 2，分别对应每个 `?*` 通配符。第一个匹配项 `mcx.match[0].str` 将指向 "BC"（`str+1`），`mcx.match[0].len == 2`；第二个匹配项 `mcx.match[1].str` 将指向 "DEF"（`str+4`），`mcx.match[1].len == 3`。

**注意**：这是一个实验性接口，结构体定义可能会在未来版本中发生变化。

### 参考

* [用户手册](../UserManual.md) 中的模式匹配部分。
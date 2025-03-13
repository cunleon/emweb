# Civetweb API 参考

### `mg_url_decode(src, src_len, dst, dst_len, is_form_url_encoded);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`src`** | `const char *` | 待转换的源数据 |
| **`src_len`** | `int` | 源缓冲区的长度 |
| **`dst`** | `char *` | 目标缓冲区，用于存储解码结果 |
| **`dst_len`** | `int` | 目标缓冲区的长度 |
| **`is_form_url_encoded`** | `int` | 当需要进行表单解码时，该值不为零 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 解码后存储在目标缓冲区中的字节数，如果目标缓冲区不存在或过小则返回 **-1** |

### 说明

函数 `mg_url_decode()` 对输入缓冲区进行解码。它既可以解码普通 URI，也可以解码表单 URI。在后一种情况下，空格字符会被转换为 `+`，这是根据 [RFC 1866](http://ftp.ics.uci.edu/pub/ietf/html/rfc1866.txt) 第 8.2.1 节的定义实现的。

### 参见

* [`mg_url_encode();`](mg_url_encode.md)
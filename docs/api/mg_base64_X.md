# Civetweb API 参考

### `mg_base64_encode(src, src_len, dst, dst_len);`  
### `mg_base64_decode(src, src_len, dst, dst_len);`

### `base64_encode` 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`src`** | `const unsigned char *` | 包含要编码为 BASE-64 的字节的源缓冲区。 |
| **`src_len`** | `size_t` | 源缓冲区中要编码的字节数。 |
| **`dst`** | `char *` | 目标字符串缓冲区。 |
| **`dst_len`** | `size_t *` | 指向一个变量，包含目标缓冲区的可用大小（以字节为单位）。 |

### `base64_decode` 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`src`** | `const char *` | 包含 BASE-64 编码数据的源字符串。 |
| **`src_len`** | `size_t` | 源缓冲区中要解码的字节数。 |
| **`dst`** | `unsigned char *` | 目标字节缓冲区。 |
| **`dst_len`** | `size_t *` | 指向一个变量，包含目标缓冲区的可用大小（以字节为单位）。 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 错误信息。返回值为 -1 表示成功。 |

### 说明

`mg_base64_encode()` 函数将源缓冲区的内容编码为 BASE-64 格式，并存储到目标缓冲区中。  
`mg_base64_decode()` 函数读取 BASE-64 编码的源缓冲区，并将其解码到目标缓冲区中。  
两个函数在成功时返回 -1。  
如果目标缓冲区空间不足，函数返回 0。  
如果传递给 `mg_base64_decode()` 的源缓冲区包含无效字符，返回值为该字符的位置。
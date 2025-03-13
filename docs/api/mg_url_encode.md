# Civetweb API 参考

### `mg_url_encode( src, dst, dst_len );`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
|**`src`**|`const char *`|需要编码的输入字符串|
|**`dst`**|`char *`|用于存储编码结果的目标缓冲区|
|**`dst_len`**|`size_t`|目标缓冲区的长度（包括终止符 `NUL`）|

### 返回值

| 类型 | 描述 |
| :--- | :--- |
|`int`|写入目标缓冲区的字符数|

### 描述

函数 `mg_url_encode()` 用于对输入缓冲区中的字符串进行编码。它可以编码普通 URI 和表单 URI。对于表单 URI，空格字符会按照 [RFC 1866](http://ftp.ics.uci.edu/pub/ietf/html/rfc1866.txt) 第 8.2.1 节的定义转换为 `+`。

### 相关函数

* [`mg_url_decode();`](mg_url_decode.md)
# EmWeb API Reference

### `mg_base64_encode( src, src_len, dst, dst_len );`
### `mg_base64_decode( src, src_len, dst, dst_len );`

### Parameters `base64_encode`

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
|**`src`**|`const unsigned char *`|Source buffer containing bytes to be encoded into BASE-64 code.|
|**`src_len`**|`size_t`|Number of bytes in source buffer to be encoded.|
|**`dst`**|`char *`|Destination string buffer.|
|**`dst_len`**|`size_t *`|Pointer to a variable containing the available size of the destination buffer in bytes.|

### Parameters `base64_decode`

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
|**`src`**|`const char *`|Source string containing BASE-64 encoded data.|
|**`src_len`**|`size_t`|Number of bytes in the source buffer to be decoded.|
|**`dst`**|`unsigned char *`|Destination byte buffer.|
|**`dst_len`**|`size_t *`|Pointer to a variable containing the available size of the destination buffer in bytes.|

### Return Value

| 类型 | 描述 |
| :--- | :--- |
|`int`|Error information. -1 indicates success.错误信息，-1 表示操作成功|

### Description

BASE64 编解码函数说明
mg_base64_encode()
功能：将源缓冲区（source buffer）的数据进行 BASE64 编码，结果写入目标缓冲区（destination buffer）。
返回值：
-1：编码成功。
0：目标缓冲区空间不足。
mg_base64_decode()
功能：读取 BASE64 编码的源缓冲区数据，将其 解码 后写入目标缓冲区。
返回值：
-1：解码成功。
0：目标缓冲区空间不足。
正整数：表示源缓冲区中存在无效字符的位置（索引值）。

注意事项
成功标识特殊：两个函数均以 -1 表示操作成功（与常规的 0 成功标识不同，需特别注意）。
缓冲区检查：调用前需确保目标缓冲区足够大，否则返回 0。
无效字符处理：解码时若源数据非法，返回值直接指向问题字符的位置，便于调试。

The function `mg_base64_encode()` encodes the source buffer into the destination buffer using BASE-64 encoding.
The function `mg_base64_decode()` reads a BASE-64 encoded source buffer and decodes it into the destination buffer.
Both functions return -1 on success.
If the destination buffer is not big enough, the functions return 0.
If the source buffer supplied to `mg_base64_decode()` contains invalid characters, the return value is the position of this character. 

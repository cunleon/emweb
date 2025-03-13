# Civetweb API 参考

### `mg_read(conn, buf, len);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`conn`** | `struct mg_connection *` | 指向连接的指针 |
| **`buf`** | `void *` | 指向存储接收数据的缓冲区地址 |
| **`len`** | `size_t` | 缓冲区可存储的最大字节数 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `int` | 读取的字节数，或状态指示 |

### 说明

`mg_read()` 函数用于通过现有连接接收数据。数据以二进制形式处理，并存储在作为参数提供的缓冲区中。函数成功时返回读取的字节数，如果连接被对端关闭，则返回 **0**，如果无法从连接中读取更多数据，则返回负值。

### 示例代码

```c
#define RECV_BUF_SIZE 1 << 20

size_t read_data(struct mg_connection* conn,
                 uint8_t* buff,
                 size_t buff_len) {
    size_t read_len = 0;
    while (read_len < buff_len) {
        size_t sz_to_read = (sz_to_read < RECV_BUF_SIZE) ? sz_to_read : RECV_BUF_SIZE;
        int this_read = mg_read(conn, buff + read_len, sz_to_read);
        if (this_read < 0) {
            fprintf(stderr, "[error] Failed to read data\n");
            break;
        } else {
            read_len += size_t(this_read);
            if (this_read > 0) {
                fprintf(stdout, "[debug] Received %d more bytes\n", this_read);
            }
        }
    }
    return read_len;
}
```

### 参考

* [`mg_printf();`](mg_printf.md)
* [`mg_write();`](mg_write.md)
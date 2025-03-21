# Civetweb API Reference

### `mg_close_connection( conn );`

### Parameters

| Parameter | Type | Description |
| :--- | :--- | :--- |
|**`conn`**|`struct mg_connection *`|The connection which must be closed|

### Return Value

*none*

### Description

mg_close_connection() 函数用于关闭通过 mg_download() 函数打开的连接。使用此函数关闭以其他方式打开的连接是未被记录的行为，可能会产生意外的结果。

The function `mg_close_connection()` is used to close a connection which was opened with the [`mg_download()`](mg_download.md) function. Use of this function to close a connection which was opened in another way is undocumented and may give unexpected results.

### See Also

* [`mg_download();`](mg_download.md)

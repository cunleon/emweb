# Civetweb API 参考

### ~~`mg_upload( conn, destination_dir );`~~

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
|**`conn`**|`struct mg_connection *`|用于上传文件的连接|
|**`destination_dir`**|`const char *`|上传文件的目标目录|

### 返回值

| 类型 | 描述 |
| :--- | :--- |
|`int`|成功或错误代码|

### 描述

函数 `mg_upload()` 已弃用，并可能在未来的版本中移除。因此，**强烈不建议**使用此函数。

### 相关函数


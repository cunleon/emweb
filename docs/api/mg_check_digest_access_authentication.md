# Civetweb API Reference

### `mg_check_digest_access_authentication( conn, realm, filename );`

### Parameters

| Parameter | Type | Description |
| :--- | :--- | :--- |
|**`conn`**|`struct mg_connection *`| A pointer to the connection to be used to send data |
|**`realm`**|`const char *`| The requested authentication realm or NULL |
|**`filename`**|`const char *`| The path to the passwords file |

### Return Value

| Type | Description |
| :--- | :--- |
|`int`| An integer indicating success or failure |

### Description

此函数可用于检查请求标头是否包含 HTTP 摘要身份验证信息，匹配密码文件中编码的用户和密码。
如果身份验证域（也称为身份验证域）为 NULL，则参数使用服务器配置 （'mg_start（）'） 中指定的 'authentication_domain' 。

正返回值表示用户名、领域和正确的密码哈希值在 passwords 文件中找到。
返回 0 表示读取密码文件成功，但没有匹配的用户realm 和 password 的 STATE 文件。
该函数在出错时返回负数。

### See Also

* [`mg_send_digest_access_authentication_request();`](mg_send_digest_access_authentication_request.md)
* [`mg_modify_passwords_file();`](mg_modify_passwords_file.md)
* [`mg_start();`](mg_start.md)


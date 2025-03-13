# CivetWeb API 参考

CivetWeb 通常用作大型应用程序中的 HTTP 和 HTTPS 库。通过 C API 可以将 CivetWeb 的功能集成到更大的代码库中。本文档描述了公共 C API。API 的基本用法示例可以在 [Embedding.md](Embedding.md) 中找到，也可以在示例目录中找到。

C++ 封装器也可用于一些基本功能。请注意，只有 C API 提供的一小部分功能可以通过此 C++ 封装器访问。C++ 封装器未经过单元测试，也没有与此 C API 文档等效的 C++ API 文档。

## 宏

| 宏 | 描述 |
| :--- | :--- |
| **`CIVETWEB_VERSION`** | 当前软件版本，以字符串形式表示，主版本号和次版本号用点号分隔。例如，版本 1.9 的值为 "1.9"，第一个补丁版本为 "1.9.1"。 |
| **`CIVETWEB_VERSION_MAJOR`** | 当前主版本号，例如版本 1.9 的值为 (1)。 |
| **`CIVETWEB_VERSION_MINOR`** | 当前次版本号，例如版本 1.9 的值为 (9)。 |
| **`CIVETWEB_VERSION_PATCH`** | 当前补丁版本号，例如版本 1.9 的值为 (0)，版本 1.9.1 的值为 (1)。 |

## 句柄

* `struct mg_context *`  
  用于表示一个 HTTP(S) 服务器实例的句柄。  
  所有使用 `const struct mg_context *` 作为参数的函数不会修改正在运行的服务器实例，而只是查询信息。使用非 `const struct mg_context *` 作为参数的函数可能会修改服务器实例（例如，注册新的 URI、停止服务器等）。

* `struct mg_connection *`  
  用于表示一个客户端-服务器连接的句柄。  
  使用 `const struct mg_connection *` 的函数操作服务器已知的数据，而不会从客户端读取数据或向客户端发送数据。使用 `const struct mg_connection *` 作为参数的回调函数不应调用 `mg_read()` 和 `mg_write()` 系列的函数。为了支持正确的应用程序，读取和写入函数需要非 `const struct mg_connection *` 连接句柄。

这两个结构体的内容在接口中未定义——它们仅用作不透明指针（句柄）。

## 结构体

* [`struct mg_callbacks;`](api/mg_callbacks.md)
* [`struct mg_client_cert;`](api/mg_client_cert.md)
* [`struct mg_client_options;`](api/mg_client_options.md)
* [`struct mg_error_data;`](api/mg_error_data.md)
* [`struct mg_form_data_handler;`](api/mg_form_data_handler.md)
* [`struct mg_header;`](api/mg_header.md)
* [`struct mg_init_data;`](api/mg_init_data.md)
* [`struct mg_option;`](api/mg_option.md)
* [`struct mg_request_info;`](api/mg_request_info.md)
* [`struct mg_response_info;`](api/mg_response_info.md)
* [`struct mg_server_port;`](api/mg_server_port.md)
* [`struct mg_websocket_subprotocols;`](api/mg_websocket_subprotocols.md)

## 库 API 函数

* [`mg_init_library( feature );`](api/mg_init_library.md)
* [`mg_exit_library( feature );`](api/mg_exit_library.md)
* [`mg_check_feature( feature );`](api/mg_check_feature.md)
* [`mg_version();`](api/mg_version.md)

## 服务器 API 函数

* [`mg_start( callbacks, user_data, options );`](api/mg_start.md)
* [`mg_start2( init, error );`](api/mg_start2.md)
* [`mg_start_domain( ctx, configuration_options );`](api/mg_start_domain.md)
* [`mg_start_domain2( ctx, configuration_options, error );`](api/mg_start_domain2.md)
* [`mg_stop( ctx );`](api/mg_stop.md)

* [`mg_get_builtin_mime_type( file_name );`](api/mg_get_builtin_mime_type.md)
* [`mg_get_option( ctx, name );`](api/mg_get_option.md)
* [`mg_get_server_ports( ctx, size, ports );`](api/mg_get_server_ports.md)
* [`mg_get_user_data( ctx );`](api/mg_get_user_data.md)
* [`mg_set_auth_handler( ctx, uri, handler, cbdata );`](api/mg_set_auth_handler.md)
* [`mg_set_request_handler( ctx, uri, handler, cbdata );`](api/mg_set_request_handler.md)
* [`mg_set_websocket_handler( ctx, uri, connect_handler, ready_handler, data_handler, close_handler, cbdata );`](api/mg_set_websocket_handler.md)
* [`mg_set_websocket_handler_with_subprotocols( ctx, uri, subprotocols, connect_handler, ready_handler, data_handler, close_handler, cbdata );`](api/mg_set_websocket_handler_with_subprotocols.md)

* [`mg_lock_context( ctx );`](api/mg_lock_context.md)
* [`mg_unlock_context( ctx );`](api/mg_unlock_context.md)

* [`mg_get_context( conn );`](api/mg_get_context.md)

* [`mg_send_http_error( conn, status_code, fmt, ... );`](api/mg_send_http_error.md)
* [`mg_send_http_ok( conn, mime_type, content_length );`](api/mg_send_http_ok.md)
* [`mg_send_http_redirect( conn, target_url, redirect_code );`](api/mg_send_http_redirect.md)

* [`mg_send_digest_access_authentication_request( conn, realm );`](api/mg_send_digest_access_authentication_request.md)
* [`mg_check_digest_access_authentication( conn, realm, filename );`](api/mg_check_digest_access_authentication.md)
* [`mg_modify_passwords_file( passwords_file_name, realm, user, password );`](api/mg_modify_passwords_file.md)
* [`mg_modify_passwords_file_ha1( passwords_file_name, realm, user, ha1 );`](api/mg_modify_passwords_file_ha1.md)

* [`mg_get_request_info( conn );`](api/mg_get_request_info.md)
* [`mg_get_request_link( conn, buf, buflen );`](api/mg_get_request_link.md)
* [`mg_handle_form_request( conn, fdh );`](api/mg_handle_form_request.md)

* [`mg_send_file( conn, path );`](api/mg_send_file.md)
* [`mg_send_mime_file( conn, path, mime_type );`](api/mg_send_mime_file.md)
* [`mg_send_mime_file2( conn, path, mime_type, additional_headers );`](api/mg_send_mime_file2.md)
* [`mg_websocket_write( conn, opcode, data, data_len );`](api/mg_websocket_write.md)

* [`mg_response_header_*();`](api/mg_response_header_X.md)

## 客户端 API 函数

* [`mg_connect_client( host, port, use_ssl, error_buffer, error_buffer_size );`](api/mg_connect_client.md)
* [`mg_connect_client_secure( client_options, error_buffer, error_buffer_size );`](api/mg_connect_client_secure.md)
* [`mg_connect_websocket_client( host, port, use_ssl, error_buffer, error_buffer_size, path, origin, data_func, close_func, user_data);`](api/mg_connect_websocket_client.md)
* [`mg_websocket_client_write( conn, opcode, data, data_len );`](api/mg_websocket_client_write.md)

* [`mg_download( host, port, use_ssl, error_buffer, error_buffer_size, fmt, ... );`](api/mg_download.md)

* [`mg_get_response( conn, ebuf, ebuf_len, timeout );`](api/mg_get_response.md)
* [`mg_get_response_info( conn );`](api/mg_get_response_info.md)

* [`mg_connect_client2( host, protocol, port, path, init, error );`](api/mg_connect_client2.md)
* [`mg_get_response2( conn, error, timeout );`](api/mg_get_response2.md)

## 通用 API 函数

* [`mg_close_connection( conn );`](api/mg_close_connection.md)
* [`mg_cry( conn, fmt, ... );`](api/mg_cry.md)

* [`mg_get_cookie( cookie, var_name, buf, buf_len );`](api/mg_get_cookie.md)
* [`mg_get_header( conn, name );`](api/mg_get_header.md)
* [`mg_get_response_code_text( conn, response_code );`](api/mg_get_response_code_text.md)
* [`mg_get_user_connection_data( conn );`](api/mg_get_user_connection_data.md)
* [`mg_get_valid_options();`](api/mg_get_valid_options.md)
* [`mg_get_var( data, data_len, var_name, dst, dst_len );`](api/mg_get_var.md)
* [`mg_get_var2( data, data_len, var_name, dst, dst_len, occurrence );`](api/mg_get_var2.md)
* [`mg_lock_connection( conn );`](api/mg_lock_connection.md)
* [`mg_md5( buf, ... );`](api/mg_md5.md)
* [`mg_printf( conn, fmt, ... );`](api/mg_printf.md)
* [`mg_read( conn, buf, len );`](api/mg_read.md)
* [`mg_send_chunk( conn, buf, len );`](api/mg_send_chunk.md)
* [`mg_send_file_body( conn, path );`](api/mg_send_file_body.md)
* [`mg_set_user_connection_data( conn, data );`](api/mg_set_user_connection_data.md)
* [`mg_split_form_urlencoded( data, form_fields, num_form_fields);`](api/mg_split_form_urlencoded.md)
* [`mg_start_thread( f, p );`](api/mg_start_thread.md)
* [`mg_store_body( conn, path );`](api/mg_store_body.md)
* [`mg_strcasecmp( s1, s2 );`](api/mg_strcasecmp.md)
* [`mg_strncasecmp( s1, s2, len );`](api/mg_strncasecmp.md)
* [`mg_unlock_connection( conn );`](api/mg_unlock_connection.md)
* [`mg_url_decode( src, src_len, dst, dst_len, is_form_url_encoded );`](api/mg_url_decode.md)
* [`mg_url_encode( src, dst, dst_len );`](api/mg_url_encode.md)
* [`mg_write( conn, buf, len );`](api/mg_write.md)

## 诊断函数

* [`mg_get_system_info( buffer, buf_len );`](api/mg_get_system_info.md)
* [`mg_get_context_info( ctx, buffer, buf_len );`](api/mg_get_context_info.md)
* [`mg_get_connection_info( ctx, idx, buffer, buf_len );`](api/mg_get_connection_info.md)

## 已弃用/移除的函数

* [~~`mg_get_valid_option_names();`~~](api/mg_get_valid_option_names.md)
* [~~`mg_upload( conn, destination_dir );`~~](api/mg_upload.md)
* [~~`mg_get_ports( ctx, size, ports, ssl);`~~](api/mg_get_ports.md)
# Civetweb API 参考

### `mg_start(callbacks, user_data, options);`

### 参数

| 参数 | 类型 | 描述 |
| :--- | :--- | :--- |
| **`callbacks`** | `const struct mg_callbacks *` | 一个包含可选回调函数的结构体，用于处理来自 Web 服务器的请求。 |
| **`user_data`** | `void *` | 指向可选用户数据的指针。 |
| **`options`** | `char **` | 用于初始化 Web 服务器的选项列表。该列表由以 NULL 结尾的选项-值字符串对组成。 |

选项列表可用于设置以下选项：

| 选项 | 默认值 | 描述 |
| :--- | :--- | :--- |
| **`cgi_environment`** | *空* | 选项 `cgi_environment` 可以包含额外的变量，这些变量将作为标准环境变量之外的内容传递给 CGI 脚本。该列表必须是一个以逗号分隔的键值对列表，例如：`VARIABLE1=VALUE1,VARIABLE2=VALUE2`。 |
| **`cgi_interpreter`** | *空* | 选项 `cgi_interpreter` 可以包含一个可执行文件的路径，该路径将被用作 **所有** CGI 脚本的解释器，无论脚本文件扩展名是什么。如果未设置此选项（默认情况），CivetWeb 会检查 CGI 脚本的第一行，看是否定义了解释器。此第一行通常格式化为 Unix 风格 shell 脚本中常见的 shebang 行，但在 Windows 系统中也可以使用。关于语法的更多信息，请参阅维基百科页面关于 [shebang 行](http://en.wikipedia.org/wiki/Shebang_(Unix) 的介绍。如果链接无法访问，请检查链接的合法性或稍后重试。) |
| | | 例如，在一个同时使用 PHP 和 Perl CGI 脚本的 Windows 系统上，`#!/path/to/php-cgi.exe` 和 `#!/path/to/perl.exe` 必须是相应 CGI 脚本的第一行。注意，路径应为绝对路径，或相对于 CivetWeb 服务器当前工作目录的相对路径。服务器的当前工作目录可能取决于启动方式。从命令行启动时，它是可执行文件被调用的目录；而从图形桌面环境的快捷方式启动时，可能是可执行文件所在的目录、用户的默认目录或快捷方式中指定的目录，具体取决于操作系统和图形用户界面。 |
| | | 如果所有 CGI 脚本使用相同的解释器，设置选项 `cgi_interpreter` 为该可执行文件的路径会更高效，因为这样无需处理 shebang 行。使用 PHP 时，请确保指向 `php-cgi(.exe)`，而不是 `php(.exe)` 可执行文件，因为后者是一个独立的解释器，不会通过 CGI 与 CivetWeb 交互。 |
| **`cgi_pattern`** | `**.cgi$|**.pl$|**.php$` | 所有匹配 `cgi_pattern` 的文件将被视为 CGI 文件。默认模式允许 CGI 文件位于任何位置。若要将 CGI 文件限制在特定目录中，可使用 `/path/to/cgi-bin/**.cgi` 作为模式。注意，匹配的是本地文件的完整路径，而不是客户端请求中提供的 URI。 |
| **`put_delete_auth_file`** | *空* | 选项 `put_delete_auth_file` 定义了用于 PUT 和 DELETE 请求的密码文件。没有密码文件时，无法向服务器上传新文件或删除现有文件。这仅适用于直接使用 PUT 和 DELETE 方法的 HTTP 请求，而不涉及服务器端脚本。PUT 和 DELETE 请求仍可能由 Lua 脚本和 CGI 页面处理。 |

### 返回值

| 类型 | 描述 |
| :--- | :--- |
| `struct mg_context *` | 成功时返回指向上下文结构的指针，失败时返回 NULL。 |

### 描述

`mg_start()` 是初始化 Web 服务器所需的唯一函数。函数返回后，如果提供了指向上下文结构的指针，则保证服务器已启动并正在监听指定端口。如果失败，则返回 NULL 指针。Web 服务器的行为由回调函数列表和选项列表控制。回调函数可用于处理 Web 服务器遇到的应用程序特定事件。如果某个特定回调函数设置为 NULL，则 Web 服务器将使用默认回调例程。选项列表控制 Web 服务器的启动方式，包括监听端口、并行处理请求的最大线程数以及 SSL 加密设置等。

在 Unix 系统上，作为副作用，SIGCHLD 和 SIGPIPE 信号将被忽略。如果需要对这些信号进行自定义处理，则必须在调用 `mg_start()` 完成后设置信号处理器。

### 参见

* [struct mg_callbacks;](mg_callbacks.md)
* [mg_stop();](mg_stop.md)
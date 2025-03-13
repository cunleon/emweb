# Civetweb API Reference

### `mg_exit_library( );`

### Parameters

none

### Return Value

| Type | Description |
| :--- | :--- |
|`unsigned`| **0** is returned or error |

### Description

当需要卸载库时，应用程序应调用 mg_exit_library() 函数。
它可以多次调用（mg_init_library 和 mg_exit_library 是引用计数的）。
然而，调用者必须确保它不会被并行调用（不能保证它是线程安全的）。
只有在之前使用了 mg_init_library(feature); 时，才应使用 mg_exit_library();。
库的初始化和退出函数是从 1.9 版本开始引入的（作为虚拟实现），并且从 1.10 版本开始才真正生效。
为了兼容性，其他函数（例如 mg_start();）也会初始化所需的特性，
但它们不会再进行反初始化，这会在库卸载时导致内存泄漏。

### See Also

* [`mg_init_library( feature );`](mg_init_library.md)
* [`mg_check_feature( feature );`](mg_check_feature.md)

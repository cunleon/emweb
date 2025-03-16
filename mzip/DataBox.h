//数据盒子 更简单的数据库
#include <stdint.h>

#define DBOX_API 

#define MAX_NAME_LEN 32		//最大表名列名长度，字节单位，应包括\0，方便兼容c字符串

#define DBOX_ERR_FILE_OPEN		-1
#define DBOX_ERR_MEM_ALLOC		-2
#define DBOX_ERR_FILE_FORMAT	-3
#define DBOX_ERR_FILE_READ		-4


typedef struct _DBOX_CTX  DBOX_CTX;

DBOX_API int dbox_open(DBOX_CTX** dbox, const char* filename);

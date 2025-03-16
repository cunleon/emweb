//数据盒子 更简单的数据库
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include "aes.h"
#include "DataBox.h"


uint32_t crc32(const void* data, size_t len);


#define DBOX_PAGE_SIZE		1024*16				//页面大小
#define MAX_PAGE_BUFF		1024*16				//最大页面缓存内存占用 

#define TYPE_CHECK_SIZE(type, size) \
inline int sizeof_##type##_is_error() { char a[!!(sizeof(PAGE_HEADER) == 16)];return 0; }


#define UNIQUE	0X01		//唯一
							//非空约束(not null)
//希望增加 范围 枚举

typedef struct _COL_DEF {
	char		col_name[MAX_NAME_LEN];
	uint8_t		col_type;					//列数据类型
	uint8_t		col_len;					//固定长度列的长度
	uint16_t	col_offset;					//列在记录内的偏移量
	uint8_t		col_constraint;				//约束

}COL_DEF;


typedef struct _TABLE_DEF {
	
	uint8_t		col_num;					//总列数
	uint16_t	recode_len;					//记录总长度，固定部分加可变部分指定
	uint16_t	root_page_id;				//根页id,由此限制最大文件大小 64K*16k=1024
	char		tab_name[MAX_NAME_LEN];		//表名
	COL_DEF		col_arry[0];//				//
}TABLE_DEF;


#define PAGE_SIGNATURE	0x786F4244	//DBox
//页头，每页都存在
typedef struct _PAGE_HEADER {
	uint32_t	signnture;
	uint32_t	crc32;							//crc 校验，同时具有签名页头功能，正常CRC算法加盐
	uint16_t	table_id;						//当前页所属表ID
	uint16_t	next_page_id;					//下一页的ID
	uint16_t	page_row_num;					//本页行数
	uint16_t	max_free_size;					//最大连续空闲空间
	uint8_t		page_type;						//页类型 根页 叶子页 溢出页
	uint8_t		unused_1;						//
	uint8_t		unused_3;						//
	uint8_t		unused_4;						//
} PAGE_HEADER;
//用于编译基本检查此结构体大小，要求页头大小为32，方便AES加密时跳过头
//inline int sizeof_pageheader_error() { char a[sizeof(PAGE_HEADER) == 32]; return 0; }
#define PAGE_TYPE_FILE_HEADER		1
#define PAGE_TYPE_TABLE_SPACE		2
#define PAGE_TYPE_索引空间			 3


typedef struct _FILE_HEADER {
	uint32_t signnture;
}FILE_HEADER;

//页面缓存内存索引结构
typedef struct _BUFF_INDEX {
	uint32_t page_id;				//page id
	uint16_t page_index_flag;		//标志 是否脏页 索引页   
	uint8_t* page_data;
}BUFF_INDEX;


//打开的数据库上下文
struct _DBOX_CTX {
	aes_context		aes_ctx_enc;		//加密上下文
	aes_context		aes_ctx_dec;		//解密上下文
	FILE*			pf_dbox;			//数据库文件
	uint8_t			page_flag;			//页面特性标志 crc32 aes 等

	uint32_t		buff_max_page;		//最大可缓存页面数
	uint32_t		buff_page_num;		//已缓存页面数
	BUFF_INDEX*		buff_index;			//用以记录哪些页已经缓存，改写，访问次数 访问时间等信息
};

#define PAGE_FLAG_CRC32		0x01
#define PAGE_FLAG_AES256	0x02


//数据页落地
static int write_page_to_file(DBOX_CTX* db, uint16_t page_id, uint8_t* page)
{
	PAGE_HEADER* header = (PAGE_HEADER*)page;
	header->signnture = PAGE_SIGNATURE;

	if (db->page_flag & PAGE_FLAG_CRC32) {
		header->crc32 = 0x70777077;
		uint32_t checksum = crc32(page, DBOX_PAGE_SIZE);
		header->crc32 = checksum;
	}
	if (db->page_flag& PAGE_FLAG_AES256) {

	}
	return 0;
}
static int page_read(DBOX_CTX* db, uint16_t page_id, uint8_t* page)
{

	return 0;
}

static int dbox_set_key(DBOX_CTX* dbox, void* key)
{
	aes_init(&dbox->aes_ctx_enc);
	aes_init(&dbox->aes_ctx_enc);
	aes_setkey_enc(&dbox->aes_ctx_enc, key, 256);
	aes_setkey_enc(&dbox->aes_ctx_dec, key, 256);
	return 0;
}
DBOX_API int dbox_new(DBOX_CTX** dbox, const char* filename, void* key)
{
	//新建数据库
	FILE*		pf		= NULL;
	uint8_t*	page_0	= NULL;

	pf = fopen(filename, "wb+");
	if (pf == NULL) {
		return DBOX_ERR_FILE_OPEN;
	}
	page_0 = (uint8_t*)malloc(DBOX_PAGE_SIZE);
	if (page_0 == NULL) {
		return  DBOX_ERR_MEM_ALLOC;
	}
	PAGE_HEADER* page_header = (PAGE_HEADER*)page_0;
	page_header->signnture = PAGE_SIGNATURE;
	page_header->page_type=



	return 0;
}
DBOX_API int dbox_open(DBOX_CTX** dbox, const char* filename,void * key)
{
	FILE*		pf		= NULL;
	uint8_t*	page_0	= NULL;
	DBOX_CTX*	db		= NULL;
	size_t		sz		= 0;
	pf = fopen(filename, "rb+");
	if (pf == NULL){
		return DBOX_ERR_FILE_OPEN;
	}
	page_0 = (uint8_t*)malloc(DBOX_PAGE_SIZE);
	if (page_0 == NULL) {
		return  DBOX_ERR_MEM_ALLOC;
	}
	sz = fread(page_0, DBOX_PAGE_SIZE, 1, pf);
	if (sz != DBOX_PAGE_SIZE) {
		free(page_0);
		return DBOX_ERR_FILE_READ;
	}
	
	FILE_HEADER* file_header = (FILE_HEADER*)(page_0 + sizeof(PAGE_HEADER));
	if (file_header->signnture != PAGE_SIGNATURE){
		free(page_0);
		return DBOX_ERR_FILE_FORMAT;
	}
	char signstr[]= { 'D','B','o','x' };
	uint32_t* p = (uint32_t *)signstr;
	uint32_t sign = *p;

	DBOX_CTX* db = malloc(sizeof(DBOX_CTX));
	if (db == NULL) {
		free(page_0);
		return  DBOX_ERR_MEM_ALLOC;
	}
	dbox_set_key(db, key);
	*dbox = db;
	return 0;
}
DBOX_API int dbox_flush(DBOX_CTX* dbox)
{
	//刷新存盘
	return 0;
}
DBOX_API int dbox_close(DBOX_CTX* dbox)
{
	dbox_flush(dbox);

	free(dbox);
	return 0;
}
DBOX_API int dbox_insert(DBOX_CTX* db, const char* tablename, const char* colnames, void** values, int value_num)
{


	return 0;
}

DBOX_API int dbox_insert_test(DBOX_CTX* db)
{
	void* values[] = { "aaa","bbb" };
	dbox_insert(db, "talbename", "id,name,note", values, sizeof(values));
	return 0;
}


// 计算 CRC32 校验和
static uint32_t crc32(const void* data, size_t len)
{
	uint32_t POLY = 0xEDB88320UL;//多项式除数 0xEDB88320
	const uint8_t* bytes = data;
	uint32_t crc = 0xFFFFFFFFUL;
	// 循环处理每个字节
	for (size_t i = 0; i < len; i++) {
		crc ^= bytes[i];        // 把当前字节与 crc 的低 8 位进行异或操作

		// 处理当前字节的 8 位，每次处理一位
		for (int j = 0; j < 8; j++) {
			if (crc & 1) {      // 如果 crc 的最低位为 1，则右移并与多项式除数进行异或操作
				crc = (crc >> 1) ^ POLY;
			}
			else {            // 否则，只右移一个比特位
				crc >>= 1;
			}
		}
	}
	return ~crc;                // 取反操作得到最终结果
}

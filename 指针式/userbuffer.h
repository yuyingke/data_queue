#ifndef _USER_BUFFER_H
#define _USER_BUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define	DATA_BUF_SIZE		20		//数据缓存大小

typedef struct {
	uint16_t buf[DATA_BUF_SIZE];
	uint16_t index_w;
	uint16_t index_r;
}DATA_BUFFER_T;

void user_buff_put_data(DATA_BUFFER_T* data_buf, uint16_t data);
void user_buff_get_near_num_data(DATA_BUFFER_T* data_buf, uint16_t* pdata, uint16_t num);

#ifdef __cplusplus
}
#endif

#endif

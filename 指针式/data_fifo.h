#ifndef __DATA_FIFO_H_
#define __DATA_FIFO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define	DATA_BUF_SIZE		600		//数据缓存大小
#define	DATA_FIFO_NUM		10		//数据缓存数量

typedef struct {
	uint16_t len;
	uint8_t buf[DATA_BUF_SIZE];
}DATA_ELEMENT_T;

typedef struct {
	DATA_ELEMENT_T data[DATA_FIFO_NUM];
	uint16_t index_w;
	uint16_t index_r;
}DATA_FIFO_T;

void data_fifo_init(DATA_FIFO_T *fifo);
uint16_t data_fifo_get_put_num(DATA_FIFO_T *fifo);
uint16_t data_fifo_get_empty_num(DATA_FIFO_T *fifo);
uint16_t data_fifo_put_data(DATA_FIFO_T *fifo, uint8_t *data, uint16_t data_len);
uint16_t data_fifo_out_data(DATA_FIFO_T *fifo, uint8_t *data, uint16_t data_len);

#ifdef __cplusplus
}
#endif

#endif

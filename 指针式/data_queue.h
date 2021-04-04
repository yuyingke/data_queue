#ifndef __DATA_QUEUE_H_
#define __DATA_QUEUE_H_


#define	DATA_QUEUE_BUF_SIZE		10		//数据缓存大小

typedef struct {
	unsigned char data_buf[DATA_QUEUE_BUF_SIZE];
	unsigned char *data_buf_in;
	unsigned char *data_buf_out;
}DATA_QUEUE_T;

void data_queue_init(DATA_QUEUE_T *queue);
unsigned short data_queue_put_size(DATA_QUEUE_T *queue);
unsigned short data_queue_empty_size(DATA_QUEUE_T *queue);
unsigned short data_queue_put_data(DATA_QUEUE_T *queue, unsigned char *data, unsigned short data_len);
unsigned short data_queue_out_data(DATA_QUEUE_T *queue, unsigned char *data, unsigned short data_len);

#endif

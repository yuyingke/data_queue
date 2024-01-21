#include "userbuffer.h"

void user_buff_put_data(DATA_BUFFER_T *data_buf, uint16_t data)
{
	data_buf->buf[data_buf->index_w] = data;
	data_buf->index_w = (data_buf->index_w + 1) % DATA_BUF_SIZE;
}

void user_buff_get_near_num_data(DATA_BUFFER_T* data_buf, uint16_t *pdata, uint16_t num)
{
	uint16_t curr_index = data_buf->index_w;

	if (num > DATA_BUF_SIZE)
		num = DATA_BUF_SIZE;

	for (uint16_t i = 0; i < num; i++)
	{
		curr_index = (curr_index - 1 + DATA_BUF_SIZE) % DATA_BUF_SIZE;
		pdata[i] = data_buf->buf[curr_index];
	}
}
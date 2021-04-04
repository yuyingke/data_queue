#include "data_queue.h"


/**
 * @brief  数据初始化
 * @param  queue : 队列
 * @return Null
 */
void data_queue_init(DATA_QUEUE_T *queue)
{
    queue->data_i_index = 0;
	queue->data_o_index = 0;
	queue->data_size = 0;
}

/**
 * @brief  获取已存入队列数据大小
 * @param  queue : 队列
 * @return 已存入队列数据大小
 */
unsigned short data_queue_put_size(DATA_QUEUE_T *queue)
{
	return queue->data_size;
}

/**
 * @brief  获取队列空闲大小
 * @param  queue : 队列
 * @return 队列空闲大小
 */
unsigned short data_queue_empty_size(DATA_QUEUE_T *queue)
{
	return DATA_QUEUE_BUF_SIZE - queue->data_size -1;
}

/**
 * @brief 存入数据
 * @param queue : 队列
		  data : 数据地址
		  data_len : 数据大小
 * @return data_len : 存入数据大小
 */
unsigned short data_queue_put_data(DATA_QUEUE_T *queue, unsigned char *data, unsigned short data_len)
{
	unsigned short queue_empty_size = DATA_QUEUE_BUF_SIZE - queue->data_size -1;
	
	if(queue_empty_size < data_len)
	{
		data_len = queue_empty_size;
	}
	
	
	for(unsigned short len = 0; len < data_len; len ++)
	{
		queue->data_buf[queue->data_i_index] = data[len];
		(queue->data_i_index) ++;
		if(queue->data_i_index > DATA_QUEUE_BUF_SIZE)
		{
			queue->data_i_index = 0;
		}
	}
	
	queue->data_size += data_len;
	
	return data_len;
}

/**
 * @brief 取出数据
 * @param queue : 队列
		  data : 数据地址
		  data_len : 数据大小
 * @return data_len : 取出数据大小
 */
unsigned short data_queue_out_data(DATA_QUEUE_T *queue, unsigned char *data, unsigned short data_len)
{
	if(queue->data_size < data_len)
	{
		data_len = queue->data_size;
	}
	
	for(unsigned short len = 0; len < data_len; len ++)
	{
		data[len] = queue->data_buf[queue->data_o_index];
		(queue->data_o_index) ++;
		if(queue->data_o_index > DATA_QUEUE_BUF_SIZE)
		{
			queue->data_o_index = 0;
		}
	}
	
	queue->data_size -= data_len;
	
	return data_len;
}

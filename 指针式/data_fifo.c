#include "data_fifo.h"


/**
 * @brief  fifo 数据初始化
 * @param  fifo : fifo
 * @return Null
 */
void data_fifo_init(DATA_FIFO_T *fifo)
{
    fifo->index_w = 0;
	fifo->index_r = 0;
}

/**
 * @brief  获取已存入 fifo 数据数量
 * @param  fifo : fifo
 * @return 已存入 fifo 数据数量
 */
uint16_t data_fifo_get_put_num(DATA_FIFO_T *fifo)
{
	return (fifo->index_w - fifo->index_r + DATA_FIFO_NUM) % DATA_FIFO_NUM;
}

/**
 * @brief  获取 fifo 空闲大小
 * @param  fifo : fifo
 * @return fifo 空闲大小
 */
uint16_t data_fifo_get_empty_num(DATA_FIFO_T *fifo)
{
	return DATA_FIFO_NUM - 1 - data_fifo_get_put_num(fifo);
}

/**
 * @brief 存入数据
 * @param fifo : fifo
		  data : 数据地址
		  data_len : 数据大小
 * @return len : 存入数据大小
 */
uint16_t data_fifo_put_data(DATA_FIFO_T *fifo, uint8_t *data, uint16_t data_len)
{
	uint16_t len = 0;
	uint16_t fifo_empty_num = data_fifo_get_empty_num(fifo);
	
	if(fifo_empty_num > 0)
	{
		if(DATA_BUF_SIZE < data_len)
		{
			data_len = DATA_BUF_SIZE;
		}
		
		len = data_len;

		memcpy(fifo->data[fifo->index_w].buf, data, len);
		ifo->data[fifo->index_w].len = len;

		fifo->index_w ++;
	}

	return len;
}

/**
 * @brief 取出数据
 * @param queue : 队列
		  data : 数据地址
		  data_len : 数据大小
 * @return data_len : 取出数据大小
 */
uint16_t data_fifo_get_data(DATA_FIFO_T *fifo, uint8_t *data, uint16_t data_len)
{
	uint16_t len = 0;
	uint16_t fifo_put_num = data_fifo_get_put_num(fifo);

	if(fifo_put_num > 0)
	{
		// 依赖 data_fifo_put_data 函数检查
		// if(DATA_BUF_SIZE < data_len)
		// {
		// 	data_len = DATA_BUF_SIZE;
		// 	len = data_len;
		// }
		
		len = fifo->data[fifo->index_r].len;

		memcpy(data, fifo->data[fifo->index_r].buf, len);

		fifo->index_r ++;
	}
	
	return len;
}

/**
 * @brief 获取当前可存入数据地址和数据大小
 * @param fifo : fifo
		  data_len : 数据大小
 * @return 数据地址
 */
uint8_t *data_fifo_get_curr_write_point_and_len(DATA_FIFO_T *fifo, uint16_t *data_len)
{
	uint16_t fifo_empty_num = data_fifo_get_empty_num(fifo);
	uint8_t *p_data = NULL;

	p_data = fifo->data[fifo->index_w].buf;
	*data_len = DATA_BUF_SIZE;

	return p_data;
}

/**
 * @brief 当前存入数据完成
 * @param fifo : fifo
		  data_len : 数据大小
 * @return len : 实际存入数据大小
 */
uint16_t data_fifo_get_curr_write_point_and_len_done(DATA_FIFO_T *fifo, uint16_t data_len)
{
	uint16_t len = 0;
	uint16_t fifo_empty_num = data_fifo_get_empty_num(fifo);
	
	if(fifo_empty_num > 0)
	{
		if(DATA_BUF_SIZE < data_len)
		{
			data_len = DATA_BUF_SIZE;
		}
		
		len = data_len;

		ifo->data[fifo->index_w].len = len;

		fifo->index_w ++;
	}

	return len;
}

/**
 * @brief 获取当前可读出数据地址和数据大小
 * @param fifo : fifo
		  data_addr : 
		  data_len : 数据大小
 * @return 数据地址 : NULL，无；其他，成功
 */
uint8_t *data_fifo_get_curr_read_point_and_len(DATA_FIFO_T *fifo, uint16_t *data_len)
{
	uint16_t len = 0;
	uint16_t fifo_put_num = data_fifo_get_put_num(fifo);
	uint8_t *p_data = NULL;

	if(fifo_put_num > 0)
	{
		len = fifo->data[fifo->index_r].len;

		p_data = fifo->data[fifo->index_r].buf;

		*data_len = len;
	}

	return p_data;
}

/**
 * @brief 当前读出数据完成
 * @param fifo : fifo
		  data_len : 数据大小
 * @return len : 实际存入数据大小
 */
uint16_t data_fifo_get_curr_read_point_and_len_done(DATA_FIFO_T *fifo, uint16_t data_len)
{
	uint16_t len = 0;
	uint16_t fifo_put_num = data_fifo_get_put_num(fifo);
	uint8_t *p_data = NULL;

	if(fifo_put_num > 0)
	{
		// 依赖 data_fifo_put_data 函数检查
		// if(DATA_BUF_SIZE < data_len)
		// {
		// 	data_len = DATA_BUF_SIZE;
		// }
		
		len = fifo->data[fifo->index_r].len;

		fifo->index_r ++;
	}

	return len;
}



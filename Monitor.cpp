// 管程实现生产者与消费者

#define N 50

// 定义管程
class Monitor{

	// 定义含N个数据的环形缓冲区
	int buffer[N];

	// in表示环形队列队尾指针，out表示环形队列队头指针
	int in, out;

	// notfull表示队列未满的信号量，notempty表示队列非空的信号量
	semaphore notfull;
	semaphore notempty;

	// 缓冲区中数据个数
	int count;

	// 生产者放入数据
	public static void put(int x)
	{
		// 如果队列已满,则需要等待队列空闲才能放入数据
		if(count >= N)
			P(notfull);

		// 放入数据
		// in指向最后一个元素的下一个位置
		buffer[in] = x;
		in = (in + 1) % N;
		count++;
		// 释放队列非空的信号
		V(notempty);

	}

	// 无返回值，所以有形参
	public static void get(int x)
	{
		// 如果队列为空，则需要队列有数据才能取到数据
		if(count <= 0)
			P(notempty);

		// 取出数据
		// out指向队首元素
		x = buffer[out];
		out = (out + 1) % N;
		count--;
		// 释放队列不满的信号
		V(notfull);
	}
}

// 生产者
void producer()
{
	int x;
	while(TRUE)
	{
		/* 准备放入数据 */
		Monitor.put(x);
	}
}

// 消费者
void consumer()
{
	int x;
	/* 准备取数据 */

	Monitor.get(x);


// 主函数
void main()
{
	producer();
	consumer();
	consumer();
}
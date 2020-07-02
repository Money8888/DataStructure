// 读者写者问题


// 读者优先问题
// 即只要一个读者在读，后续的其他读者无论是否在写者后面都可以读
// 写者必须等待，必须等所有读者都读完才能写入

// 信号量
// 互斥读者与读者
semaphore rmutex = 1;
// 互斥读者与写者，写者与写者
semaphore mutex = 1;
// 表示读者数量，需看成临界资源，即进来一个读者就+1操作
int readcount = 0;

// 读者进程
void reader()
{
	while(TRUE)
	{
		// 互斥其他读者，只允许一个读者进入
		P(rmutex);
		if(readcount == 0)
			// 如果读者数目为0，所以就必须互斥写者
			P(mutex);
		// 读者数+1
		readcount++;
		// 释放，让其他读者进来修改readcount
		V(rmutex);

		/* 读操作 */

		// 读者离开，需要访问readcount
		P(rmutex);
		readcount--;
		// 如果此时没有读者了，表示写者可以进行写了
		if(readcount == 0)
			V(mutex);
		// 释放readcount资源
		V(rmutex);
	}
}

void writer()
{
	while(TRUE)
	{
		// 写者和一般消费者进程一样，获取信号量值
		P(mutex);

		/* 写操作 */

		// 让文件可读和可写
		V(mutex);
	}
}

void main()
{
	reader();
	writer();
	reader();
	/*.......*/
}

// 写者优先
// 即只要有写者在写，无论后续写者在哪都可以写，读者必须等所有写者写完才能读

// 互斥读者与写者
semaphore mutex = 1;
// 互斥读者
semaphore rmutex = 1;
// 互斥写者
semaphore wmutex = 1;
// 表示是否还有写者
semaphore readable = 1;

// 读者数量，写者数量
int readcount = 0, writecount = 0;

void reader()
{
	// 先看是否可读
	P(readable);
	// 互斥其他读者修改readcount
	P(rmutex);
	if(readcount == 0)
		// 如果没有读者，需要互斥写者
		P(mutex);
	readcount++;
	V(rmutex);
	V(readable);
	/* 读取中 */
	P(rmutex);
	if(readcount == 0)
		V(mutex);
	V(rmutex);
}

void writer()
{
	// 互斥其他写者，写入writecount
	P(wmutex);
	if(writecount == 0)
		// 此时不能让写者以后的读者进去
		P(readable)
	writecount++;
	V(wmutex);
	// 互斥在写者之前的读者
	P(mutex);
	/* 写入中 */
	// 写入完成离开
	V(mutex);
	P(wmutex);
	writecount--;
	if(writecount == 0)
		// 让写者以后的读者可读
		V(readable);
	V(wmutex);

}

void main()
{
	reader();
	writer();
	reader();
	/* ... */
}

// 读写公平算法
// 按照读者写者的先后顺序
// 互斥读者与写者
semaphore mutex = 1;
// 互斥读者
semaphore rmutex = 1;
// 只检测临界区是否还有写者
semaphore wmutex = 1;

int readcount = 0;

void reader()
{
	while(TRUE)
	{
		// 检查是否有写者
		P(wmutex);
		// 互斥其他读者
		P(rmutex);
		if(readcount == 0)
			// 互斥写者
			P(mutex);
		readcount++;
		V(rmutex);
		// 让写者也能进入
		V(wmutex);

		/* 读取中 */

		P(rmutex);
		readcount--;
		if(readcount == 0)
			V(mutex);
		V(rmutex);
	}
}

void writer()
{
	while(TRUE)
	{
		// 如果后续的写者进来，申请到wmutex，则等读者释放后进入第二步申请mutex
		// 此时如果有后来读者想进入，但wmutex已经为0，明显不能进来
		// 所以此时只能是写者等到上一个读者释放mutex并获取后进入写操作，最后释放wmutex后才能让后来的读者进入
		P(wmutex);
		P(mutex);

		/* 写入中*/

		V(mutex);
		V(wmutex);
	}
}
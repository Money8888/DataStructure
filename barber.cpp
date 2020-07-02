
// 理发师问题

// 沙发个数
#define N 5
// 顾客等待时所坐的沙发数
int count = 0;

// 互斥访问count
semaphore mutex = 1;
// 理发椅是否为空
semaphore empty = 1;
// 表示理发椅上是否有顾客
semaphore full = 0;
// 等待顾客付费
semaphore payment = 0;
// 理发师收费
semaphore receipt = 0;

void consumer()
{
	// 申请访问count
	P(mutex);
	if(count >= N)
	{
		V(mutex);
		/* 离开 */
	}
	else
	{
		// 说明沙发有空位
		count++;
		V(mutex);
		/* 就坐 */
		// 申请理发椅
		P(empty);
		// 坐到理发椅上，此时沙发数减一
		P(mutex);
		count--;
		V(mutex);
		// 释放理发椅已满的信号
		V(full);
		/* 开始理发 */
		// 准备付费
		// 释放要付钱的信号
		V(payment);
		// 等待理发师收费
		P(receipt);
		// 离开理发椅
		V(empty);
	}
}

// 类似一个生产者多个消费者,所以需要循环
void Barber()
{
	while(TRUE)
	{
		// 查看是否有顾客在理发椅上
		P(full);
		/* 理发 */
		// 接收顾客付费信号
		P(payment);
		// 收钱
		V(receipt);
	}
}
#include<stdio.h>
#define N 20
typedef int semaphore;
typedef int item;
semaphore mutex = 1;//互斥信号量。-1为被占用且有进程在等待，0为正在运行，1为空闲状态
semaphore empty = N;//目前缓冲池有N个空位可以生产
semaphore full = 0;//缓冲池中已生产元素个数
item buffer[N] = {};//N个缓冲区
int in = 0, out = 0;//in==out为空;(in+1)%N==out为满
int wait(int S) {
	S--;
	return S;
}
int signal(int S) {
	S++;
	return S;
}
/*生产者，实现键盘输入向缓冲区中生产*/
item* producer() {
	item nextp;//生产元素
	int i;
	printf("input the number of producer<20:");
	scanf_s("%d", &i);//输入要生产元素的个数
	while (i>0 && i<N) {
		empty = wait(empty);//看有没有地方放
		if (empty>0) {
			mutex = wait(mutex);//临界资源是否被占用
			if (mutex == 0) {
				printf("please input nextp：");
				scanf_s("%d", &nextp);
				buffer[in] = nextp;//向缓冲区添加数据
				in = (in + 1) % N;//in指针指向下一个元素
				printf("success\n");
				mutex = signal(mutex);//mutex 0->1
				full = signal(full);//full+1
			}
		}
		i--;
	}
	return buffer;
}
/*每次消费缓冲池中的第一个元素，缓冲区为空时不可消费*/
item* consumer() {
	item nextc;
	/*实现消费多个只要一个循环即可*/
	full = wait(full);
	if (full >= 0) {
		mutex = wait(mutex);
		if (mutex == 0) {
			nextc = buffer[out];
			printf("consumer the item in nextc successfully:%d", nextc);
			out = (out + 1) % N; //消费指针指向下一个位置
			mutex = signal(mutex);
		}
		else {
			printf("mutex is busy\n");
		}
		empty = signal(empty);
	}
	else
	{
		printf("error：full == 0！\n");
	} 
	return buffer;
}
void main() {
	producer();
	consumer();
}
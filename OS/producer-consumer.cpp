#include<stdio.h>
#define N 20
typedef int semaphore;
typedef int item;
semaphore mutex = 1;//�����ź�����-1Ϊ��ռ�����н����ڵȴ���0Ϊ�������У�1Ϊ����״̬
semaphore empty = N;//Ŀǰ�������N����λ��������
semaphore full = 0;//�������������Ԫ�ظ���
item buffer[N] = {};//N��������
int in = 0, out = 0;//in==outΪ��;(in+1)%N==outΪ��
int wait(int S) {
	S--;
	return S;
}
int signal(int S) {
	S++;
	return S;
}
/*�����ߣ�ʵ�ּ��������򻺳���������*/
item* producer() {
	item nextp;//����Ԫ��
	int i;
	printf("input the number of producer<20:");
	scanf_s("%d", &i);//����Ҫ����Ԫ�صĸ���
	while (i>0 && i<N) {
		empty = wait(empty);//����û�еط���
		if (empty>0) {
			mutex = wait(mutex);//�ٽ���Դ�Ƿ�ռ��
			if (mutex == 0) {
				printf("please input nextp��");
				scanf_s("%d", &nextp);
				buffer[in] = nextp;//�򻺳����������
				in = (in + 1) % N;//inָ��ָ����һ��Ԫ��
				printf("success\n");
				mutex = signal(mutex);//mutex 0->1
				full = signal(full);//full+1
			}
		}
		i--;
	}
	return buffer;
}
/*ÿ�����ѻ�����еĵ�һ��Ԫ�أ�������Ϊ��ʱ��������*/
item* consumer() {
	item nextc;
	/*ʵ�����Ѷ��ֻҪһ��ѭ������*/
	full = wait(full);
	if (full >= 0) {
		mutex = wait(mutex);
		if (mutex == 0) {
			nextc = buffer[out];
			printf("consumer the item in nextc successfully:%d", nextc);
			out = (out + 1) % N; //����ָ��ָ����һ��λ��
			mutex = signal(mutex);
		}
		else {
			printf("mutex is busy\n");
		}
		empty = signal(empty);
	}
	else
	{
		printf("error��full == 0��\n");
	} 
	return buffer;
}
void main() {
	producer();
	consumer();
}
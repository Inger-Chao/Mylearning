#include<stdio.h>
#define M 3
#define N 5
typedef int Process;
typedef int Resource;
Resource Available[M];
Resource Max[N][M];
Resource Allocation[N][M];
Resource Need[N][M];

void banker(Process p,int request[M]) {

	int i = p , j;
	
	for ( j = 0; j < M; j++)
	{
		if (request[j] <= Need[i][j])
		{
			if (request[j] <= Available[j])
			{
				//尝试把资源分配给进程P，并修改数据结构中的数值
				Available[j] = Available[j] - request[j];
				Allocation[i][j] = Allocation[i][j] + request[j];
				Need[i][j] = Need[i][j] - request[j];
				printf("\nResourse%d allocation success", j);
				
			}
			else
			{
				printf("\nResourse %d:There is not enough resourse", j);
			}
		}
		else
		{
			printf("\nError!Resourse%d:The number of resourse you request has beyond the number of your starting number\n" , j);
		}
	}
	
}

void security() {
	Resource *Work = Available;
	Process line[N];
	int i, j;
	bool Finish[N];
	printf("Input Process line:");
	for ( i = 0; i < N; i++)
	{
		scanf("%d", &line[i]);
	}

	printf("\n Test Work: %d %d %d" , Work[0],Work[1],Work[2]);
	for ( i = 0; i < N; i++)
	{
		Finish[i] = false;
	}
	for ( i = 0; i < N; i++)
	{
		for ( j = 0; j < M; j++)
		{
			if (Finish[line[i]] == false && Need[line[i]][j] <= Work[j]) {
				Work[j] = Work[j] + Allocation[line[i]][j];
				Finish[line[i]] = true;
			}
		}
		if (Finish[line[i]] == true)
		{
			printf("\nProcess%d is security!", line[i]);
		}
		else {
			printf("\nProcess%d is not security!", line[i]);
		}
	}
}

int main() {
	int i;
	int j;

	Process p; //请求进程
	int Request[M];//请求向量

	printf("Please Input Available of A/B/C:");
	for (i = 0; i < M; i++) {
		scanf("%d", &Available[i]);
	}
	for ( i = 0; i < N; i++)
	{
		printf("\nPlease Input Max of Process%d:", i);
		for ( j = 0; j < M; j++)
		{
			scanf("%d", &Max[i][j]);
		}
	}
	printf("\n Test Max Vector:\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++) {
			printf(" %d ", Max[i][j]);
		}
		printf("\n");
	}

	for ( i = 0; i < N; i++)
	{
		printf("\nPlease Input Allocation of Process%d:",i);
		for ( j = 0; j <M ; j++)
		{
			scanf("%d", &Allocation[i][j]);
			Need[i][j] = Max[i][j] - Allocation[i][j];
			Available[j] = Available[j] - Allocation[i][j];
		}
	}

	printf("\n Test Allocation Vector:\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++) {
			printf(" %d ", Allocation[i][j]);
		}
		printf("\n");
	}

	printf("\n Test Need Vector:\n");
	for ( i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++) {
			printf(" %d ", Need[i][j]);
		}
		printf("\n");
	}
	printf("\nAvailable Vecotr : %d %d %d", Available[0], Available[1], Available[2]);
		security();
	printf("\nInput a Request Process:");
	scanf("%d", &p);
	printf("\nInput a Vector of Request Process:");
	for ( j = 0; j < M; j++)
	{
		scanf("%d", &Request[j]);
	}
	banker(p,Request);
	security();
	return 0;
}
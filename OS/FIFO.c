#include<stdio.h>
#define M 3
#define PAGES 20
int page[PAGES] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
int result[M][PAGES];
typedef struct {
	int page;
	int time;
}pBlock;

/*初始化内存矩阵*/
void init(pBlock *pb){
	int i,j;
	for(i = 0;i<M;i++){
		pb[i].page = -1;
		pb[i].time = -1;
		for(j = 0; j <PAGES ;j++){
			result[i][j] = -1;
		} 
	}
}

/*查询内存块中是否有当前页面*/
int isHavePage(pBlock *pb,int page){
	int i,j;
	int flag = 0;
	for(i = 0; i < M;i++){
		if(pb[i].page == page){
			flag = 1;
			break;
		}
	}
	return flag;
}

void printPage(int *page,int m){
	int i = 0;
	for(i = 0; i < m ;i++){
		printf("%d ",page[i]);
	}
	printf("\n");
}

void printResultArr(int result[M][PAGES]){
	int i, j;
	for (i = 0; i<M; i++) {
		for (j = 0; j<PAGES; j++) {
			if (result[i][j] == -1)
				printf("_ ");
			else
				printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}

void fifo(pBlock *pb){
	int lps = 0; //缺页次数
	double lpp = 0;//缺页率 
	int sw = 0;//替换指针
	int index;//页面号索引 
	int i;
	while(index < PAGES){
		if(!isHavePage(pb,page[index])){//如果该页面不在内存块中,pb:内存块，page[index]当前页面 
			 
			pb[sw].page = page[index];
			sw = (sw + 1) % M;
			lps++;
			for( i =0; i < M ;i++){
				result[i][index] = pb[i].page;
			}
		}
		index++;
	}
	printf("FIFO算法所得缺页次数为 %d\n", lps);
	lpp = (double)lps / PAGES;
	printf("FIFO算法缺页率为 %0.4lf \n", lpp);
	printf("页面号序列为:\n");
	printPage(page, PAGES);
	printf("结果数列为:\n");
	printResultArr(result);
	
}
/*返回要被替换的页面所在的内存快号*/
int getLong(pBlock *pb){
	int i;
	int sw = 0;
	int in = 1;//可以替换的物理块的值设为1 
	for(i = 0; i < M;i++){
		if(pb[i].time == -1){//如果内存块中为空，则往里面可以添加页面 ，跳出循环
			sw = i;//替换指针所指的物理块赋值为空的物理块索引号
			in = 0;//已经放进来东西了之后，可继续添加的页面块数-1 赋值为0 
			break;
		}
	}
	/*当还没有添加页面时，说明内存块已满，需要替换*/
	if(in){
		for(i = 0;i < M;i++){
		//	printf("pb[%d].time = %d\n",i,pb[i].time); 
			if(pb[i].time > pb[sw].time){//如果内存块第i块中页面的时间量大于可以可替换页面的的时间量，则替换最久没用的页面 
				sw = i;
			}
		}
	}
	return sw;
}
/*找到该页面在第几个内存块*/
int findPage(pBlock *pb,int page){
	int i;
	int num = -1;
	for (i = 0; i<M; i++) {
		if (pb[i].page == page) {
			num = i;
		}
	}
	return num;
}

void LRU(pBlock *pb){
	int lps = 0; //缺页次数
	double lpp = 0;//缺页率 
	int sw = 0;//替换指针,取值范围为0-2 
	int index = 0;
	int i;
	while(index<PAGES){
		if(!isHavePage(pb,page[index])){//如果没有当前页，获取内存块中时间最久的页面所在的内存块号，并替换。 
			sw = getLong(pb);
		//	printf("index:%d ,sw:%d \n",index,sw); 
			pb[sw].page = page[index];
			pb[sw].time = 0;
			lps++;
			for(i = 0; i < M ;i++){
				if(i != sw && pb[i].time != -1 ){//如果i不是替换页面并且不是初始化之前的时间 
				pb[i].time++;
				
				}
			result[i][index] = pb[i].page;
			}
		}else{
			int num_inblock = findPage(pb,page[index]); 
		//	printf("找到的内存号为：%d\n",num_inblock); 
			pb[num_inblock].time = 0;
		//	printf("index:%d,已含有\n",index);
			for(i = 0;i < M ;i++){
				if(i!= num_inblock){
					pb[i].time++;
				}
			}
		}
		index++;
	}
	printf("LRU算法所得缺页次数为 %d \n", lps);
	lpp = 1.0*lps / PAGES;
	printf("LRU算法缺页率为: %0.4lf\n", lpp);
	printf("页面号序列为:\n");
	printPage(page, PAGES);
	printf("LRU结果数组为:\n");
	printResultArr(result);
}
int main(){
	pBlock pb[M];
	init(pb);
	fifo(pb);
	init(pb); 
	LRU(pb);
	return 0;
}

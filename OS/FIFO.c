#include<stdio.h>
#define M 3
#define PAGES 20
int page[PAGES] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
int result[M][PAGES];
typedef struct {
	int page;
	int time;
}pBlock;

/*��ʼ���ڴ����*/
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

/*��ѯ�ڴ�����Ƿ��е�ǰҳ��*/
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
	int lps = 0; //ȱҳ����
	double lpp = 0;//ȱҳ�� 
	int sw = 0;//�滻ָ��
	int index;//ҳ������� 
	int i;
	while(index < PAGES){
		if(!isHavePage(pb,page[index])){//�����ҳ�治���ڴ����,pb:�ڴ�飬page[index]��ǰҳ�� 
			 
			pb[sw].page = page[index];
			sw = (sw + 1) % M;
			lps++;
			for( i =0; i < M ;i++){
				result[i][index] = pb[i].page;
			}
		}
		index++;
	}
	printf("FIFO�㷨����ȱҳ����Ϊ %d\n", lps);
	lpp = (double)lps / PAGES;
	printf("FIFO�㷨ȱҳ��Ϊ %0.4lf \n", lpp);
	printf("ҳ�������Ϊ:\n");
	printPage(page, PAGES);
	printf("�������Ϊ:\n");
	printResultArr(result);
	
}
/*����Ҫ���滻��ҳ�����ڵ��ڴ���*/
int getLong(pBlock *pb){
	int i;
	int sw = 0;
	int in = 1;//�����滻��������ֵ��Ϊ1 
	for(i = 0; i < M;i++){
		if(pb[i].time == -1){//����ڴ����Ϊ�գ���������������ҳ�� ������ѭ��
			sw = i;//�滻ָ����ָ������鸳ֵΪ�յ������������
			in = 0;//�Ѿ��Ž���������֮�󣬿ɼ�����ӵ�ҳ�����-1 ��ֵΪ0 
			break;
		}
	}
	/*����û�����ҳ��ʱ��˵���ڴ����������Ҫ�滻*/
	if(in){
		for(i = 0;i < M;i++){
		//	printf("pb[%d].time = %d\n",i,pb[i].time); 
			if(pb[i].time > pb[sw].time){//����ڴ���i����ҳ���ʱ�������ڿ��Կ��滻ҳ��ĵ�ʱ���������滻���û�õ�ҳ�� 
				sw = i;
			}
		}
	}
	return sw;
}
/*�ҵ���ҳ���ڵڼ����ڴ��*/
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
	int lps = 0; //ȱҳ����
	double lpp = 0;//ȱҳ�� 
	int sw = 0;//�滻ָ��,ȡֵ��ΧΪ0-2 
	int index = 0;
	int i;
	while(index<PAGES){
		if(!isHavePage(pb,page[index])){//���û�е�ǰҳ����ȡ�ڴ����ʱ����õ�ҳ�����ڵ��ڴ��ţ����滻�� 
			sw = getLong(pb);
		//	printf("index:%d ,sw:%d \n",index,sw); 
			pb[sw].page = page[index];
			pb[sw].time = 0;
			lps++;
			for(i = 0; i < M ;i++){
				if(i != sw && pb[i].time != -1 ){//���i�����滻ҳ�沢�Ҳ��ǳ�ʼ��֮ǰ��ʱ�� 
				pb[i].time++;
				
				}
			result[i][index] = pb[i].page;
			}
		}else{
			int num_inblock = findPage(pb,page[index]); 
		//	printf("�ҵ����ڴ��Ϊ��%d\n",num_inblock); 
			pb[num_inblock].time = 0;
		//	printf("index:%d,�Ѻ���\n",index);
			for(i = 0;i < M ;i++){
				if(i!= num_inblock){
					pb[i].time++;
				}
			}
		}
		index++;
	}
	printf("LRU�㷨����ȱҳ����Ϊ %d \n", lps);
	lpp = 1.0*lps / PAGES;
	printf("LRU�㷨ȱҳ��Ϊ: %0.4lf\n", lpp);
	printf("ҳ�������Ϊ:\n");
	printPage(page, PAGES);
	printf("LRU�������Ϊ:\n");
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


#define MAXSIZE 10
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
//������ ��Ҫ�����������нڵ��Ԫ�أ����ʹ��˳������ݽṹʱ�临�Ӷȡ� 
typedef struct{
	ElemType data[MAXSIZE];
	int length;
}Vector;

/*�㷨˼�룺������������v_temp�洢ԭ���ǰp��Ԫ�أ�����ԭ˳�����p֮���Ԫ��˳��ǰ�ƣ�Ȼ��v_temp���ݴ��p������Ԫ�����ηŻص�ԭ˳���ĺ�����Ԫ��*/
Vector* CircleLeftMove(Vector *v , int p){
	Vector *v_temp = (Vector*)malloc(sizeof(Vector));
	v_temp->length =  p;
	int i;
	for(i = 0;i < v->length ;i++){
		v_temp->data[i] = v->data[i];
		v->data[i] = v->data[i+p];
	}
	for(i = 0 ; i < p ;i++){
		v->data[v->length - p + i] = v_temp->data[i];
	}
	return v;
}
/*ʱ�临�Ӷȣ�O(n) �ռ临�Ӷȣ�O(p)*/

/*�㷨˼�룺1. ��˳����е�ǰp��Ԫ������洢��
			2. �ٰ�˳����еĺ�length-p��Ԫ������洢��
			3. Ȼ�������˳�������洢��
���磺v = 1 2 3 4 5 6 7 p = 3
	1. v = 3 2 1 4 5 6 7
	2. v = 3 2 1 7 6 5 4
	3. v = 4 5 6 7 1 2 3*/
Vector* Reverse(Vector *v , int from, int to){
	int i ; 
	ElemType temp ;
	for( i = 0 ; i < (to-from+1)/2 ; i++){
		temp = v->data[from+i];
		v->data[from+i] = v->data[to-i];
		v->data[to-i] = temp;
	}
	return v;
}

Vector* CircleLeftMove2(Vector *v , int p){
	Reverse(v,0,p-1);
	Reverse(v,p,v->length-1);
	Reverse(v,0,v->length-1);
}
/*ʱ�临�Ӷȣ�O(n) �ռ临�Ӷȣ�O(1)*/
/*��������ƽ����������*/
/*�㷨˼�룺��һ�����е���λ����mid1�洢���ڶ������е���λ����mid2�洢����mid1+mid2��/2��ֵ����������λ����*/
int getAverage(Vector v1, Vector v2){
	int i;
	int sum1 = 0,sum2 = 0;
	int length = v1.length;
	for(i = 0;i < length; i++){
		sum1 += v1.data[i];
		sum2 += v2.data[i];
	}
	return ((sum1/length)+(sum2/length))/2;
}
/*ʱ�临�Ӷȣ�O(n) �ռ临�Ӷȣ�O(1)*/

/*�㷨˼�룺 
		1.��v1.data[mid1] == v2.data[mid2]����mid1��mid2��Ϊ������λ�����������ء�
		2.��v1.data[mid1] < v2.data[mid2]2��������1�б�mid1��ҪС���ز�����Ϊ������λ��������������1�н�С��һ��
						(������Ԫ�ظ���Ϊ������������λ��ǰ��Ԫ�أ���Ϊż������ȥ������λ�����ڵ�Ԫ��)��
						ͬ����ʱҲҪ��������2�нϴ��һ��
						�����������ĳ�������ȣ��������ܱ�֤ͬ�����ҵȳ�����
		3.��v1.data[mid1] > v2.data[mid2], ����������1�д���mid1������ͬʱҲҪ��������2�н�С��һ��
						(������Ԫ�ظ���Ϊ��������������2��λ����Ԫ�أ���Ϊż������ȥ������λ�����ڵ�Ԫ��)��
			ֱ���߼��ϵ�����ֻ��һ��Ԫ��ʱ����С�߼�Ϊ������λ����*/
int getMidByCompare(Vector v1,Vector v2){
	int num1 = 0,num2 = 0; //num���ʼ��ָ�������еĵ�һ��Ԫ�ص��±� 
	int end1 = v1.length - 1;
	int end2 = v2.length - 1;//end���ʼ��ָ�������е����һ��Ԫ�ص��±� 
	int mid1 , mid2;
	while(num1 != end1 || num2 != end2){
		mid1 = (num1 + end1)/2;//�߼��ϵ���λ���±� 
		mid2 = (num2 + end2)/2;
		if(v1.data[mid1] == v2.data[mid2]){
			return v1.data[mid1];
		}
		if(v1.data[mid1] < v2.data[mid2]){
			if((num1+end1) %2 == 0){
				//v1��Ԫ�ظ���Ϊ���� 
				num1 = mid1; //��������1��λ��ǰ��Ԫ��
				end2 = mid2;
			}else{
				num1 = mid1 + 1; //��������1��λ������λ��ǰ��Ԫ��
				end2 = mid2;
			}
		}else{//����1����λ����������2����λ�� 
			if((num2+end2)%2 == 0){
				end1 = mid1;//��������1�б���λ�����Ԫ��
				num2 = mid2; 
			}else{
				end1 = mid1;
				num2 = mid2+1; //��������2����λ��������λ��С��Ԫ�� 
			}
		}
	}
	return v1.data[num1] < v2.data[num2] ? v1.data[num1] : v2.data[num2];
}
/*ʱ�临�Ӷȣ�O(log2n) �ռ临�Ӷȣ�O(1)*/ 

/*�㷨˼�룺 
		������ĵ�һ��Ԫ�ؿ�ʼ������Ϊÿ��Ԫ������һ��countֵ��ʾ�����и�Ԫ��ֵ��Ԫ�ظ�����
		�ͺ����Ԫ�رȽϣ���ֵ���ʱ��count+1����ĳ��Ԫ�ص�countֵ�������鳤��һ��ʱ���̷��ظ�Ԫ�ص�ֵ��
		��ĳ��Ԫ�ص�countֵ�������鳤��һ��ʱ���̷���-1����Ϊ�ز����ܴ�����������Ԫ�ء�*/
int getMainx(int a[],int length){
	int i,j;
	for(i = 0; a[i] <length;i++){
		int count = 1;
		for( j = i+1; a[j] <length;j++){
			if(a[i] == a[j]){
				count++;			
			}
		}
		if(count > length/2){
				return a[i];
		}else if(count == length/2){
			return -1;
		}
	}
	return -1;
}
/*ʱ�临�Ӷȣ�O(n^2) �ռ临�Ӷȣ�O(1)*/ 
/*�����ⷨ����������ͳ��O(nlong2n)*/
/*���Ž⣺���һ�����ܳ�Ϊ��Ԫ�ص�Ԫ�ء�Ȼ�����¼����Ƿ�Ϊ��Ԫ�ء�
		1. ѡȡ��ѡ����Ԫ�أ������г��ִ�������Ԫ�أ���
		����ɨ�����������е�ÿ���������������ĵ�һ��Ԫ�ر��浽main�У�
		��¼��Ԫ�س��ֵĴ���Ϊ1����������һ�������Ե���main,��count+1������count-1��
		��count == 0ʱ������������һ���������浽main�У�count��������Ϊ1����ʼ��һ�ּ�����
		�ظ���������ֱ��ɨ������������Ԫ�ء�
		2.�ж�main�Ƿ�Ϊ��������Ԫ�أ��ٴα������飬ͳ��mainԪ�س��ֵĴ�����
		����������鳤��һ���򷵻�main���򷵻�-1.*/ 

int getMain(int a[],int length){
	int i, main , count = 1;
	main = a[0];
	for(i = 1;i < length;i++){
		if(a[i] == main){
			count++ ;
		}else{
			if(count>0){
				count--;
			}else{
				main = a[i];
				count = 1;
			}
		}
	}
	if(count > 0){
		for(i = count = 0;i<length;i++){
			if(a[i] == main){
				count++;
			}
		}
	}
	if(count > (length/2)){
		return main;
	}else return -1;
} 
/*ʱ�临�Ӷȣ�O(N),�ռ临�Ӷ�O(1)*/
int main(){

	int i;
	Vector v1 = { {11,13,15,17,19},5 };
	Vector v2 = { {2,4,6,8,20},5};
	int a[8] = {0,5,5,3,5,7,5,5};
	int b[8] = {0,5,2,5,5,3,5,4}; 
	int length = sizeof(a)/sizeof(a[0]);
	printf("\nThe main num is : %d" ,getMain(a,length));
	printf("\nThe main num is : %d" ,getMain(b,length));
	
	return 0;
}

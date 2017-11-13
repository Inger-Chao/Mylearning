#include<stdio.h>
#define N 20
typedef int semaphore;
typedef int item;
semaphore mutex=1;
semaphore empty=N;
semaphore full=0;
item buffer[N];
int in=0,out = 0;
int wait(int S){
    while(S<=0){
        S--;
    }
    return S;
}
int signal(int S){
    S++;
    return S;
}
item* producer(){
        item nextp;
        int i;
        printf("input the number of producer<20:");
        scanf("%d",&i);
        while(i>0&&i<N){
            if(wait(empty)>0){
            if(wait(mutex)==1){
                printf("please input nextp：");
                scanf("%d",&nextp);
                buffer[in] =nextp;
                in=(in+1) % N;
                printf("success\n");
                signal(mutex);
                signal(full);
            }
        }
        i--;
        }

        return buffer[N];
}
item* consumer(){
    item nextc;
    if(wait(full) > 0){
        if(wait(mutex) == 1){
            nextc=buffer[out];
            printf("consumer the item in nextc successfully:%d",nextc);
            out = (out+1)%N; //指向下一个位置
            signal(mutex);
        }
        signal(empty);
    }
}
void main(){
    producer();
    consumer();
}

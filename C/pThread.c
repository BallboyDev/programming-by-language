#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#include<signal.h>
#include<time.h>

void *maxnum(){              //배열100개 생성및 임의 값100개 추가
    int a[100];
    int i;
    for(i=0;i<100;i++){
        a[i]=rand() % 100;
        if(a[0]<a[i])
            a[0]=a[i];
    }
    pthread_exit((void*)a[0]);
}
int main() {
    int i;
    int result[3];
    pthread_t p_tread[3];
	srand(time(NULL));//자식스레드 3개 만들기
    for(i=0;i<3;i++){
        pthread_create(&p_tread[i],NULL,maxnum,NULL);
    }
    for(i=0;i<3;i++){
        pthread_join(p_tread[i],(void*)&result[i]);
    }
    
    //printf("max %ld %ld %ld pid:\n",result[0],result[1],result[2]);
    if(result[0]>result[1]&&result[0]>result[2])
        printf("최대 값은 : %d pthread id= p_tread[0]\n",result[0]);
	
    else if(result[1]>result[0]&&result[1]>result[2])
        printf("최대 값은 : %d pthread id= p_tread[1]\n",result[1]);
	
    else if(result[2]>result[0]&&result[2]>result[1])
        printf("최대 값은 : %d pthread id= p_tread[2]\n",result[2]);
    return 0;
}
#include <stdio.h>
#include <pthread.h>

int a,b;
void add(){printf("a+b: %d\n", a+b);}
void sub(){printf("a-b: %d\n", a-b);}

int main(){
	printf("Enter a, b\n"); scanf("%d%d",&a,&b);
	pthread_t tid1,tid2;
	printf("--> Main process\n");
	pthread_create(&tid1,NULL,add,NULL);
	pthread_create(&tid2,NULL,sub,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	printf("--> Main process\n");
}
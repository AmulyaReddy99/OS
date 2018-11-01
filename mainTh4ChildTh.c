#include <stdio.h>
#include <pthread.h>
void *id(){
	int a;
	printf("--> Thread ID: %d\nEnter a value: ",getpid()); scanf("%d",&a);
	printf("a: %d\n",a);
}
int main(){
	pthread_t tid;
	printf("--> Main process \n");
	pthread_create(&tid,NULL,id,NULL);
	pthread_join(tid,NULL);
	printf("--> Main process\n");
}
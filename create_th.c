#include <stdio.h>
#include <pthread.h>
void *id(){
	printf("Thread ID: %d\n",getpid());
}
int main(){
	pthread_t tid;
	pthread_create(&tid,NULL,id,NULL);
	printf("Main process ID: %d\n",getpid());
}
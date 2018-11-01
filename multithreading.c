#include <stdio.h>
#include <pthread.h>

int a,b;
pthread_t tid[2];
void* f(){
	pthread_t id=pthread_self();
	if(pthread_equal(id,tid[0]))
		printf("Sum: %d\n", a+b);
	if(pthread_equal(id,tid[1]))
		printf("Diff: %d\n", a-b);
}

int main(){
	pthread_t tid1,tid2; int i;
	printf("--> Main Thread\nEnter a,b "); scanf("%d%d",&a,&b);
	for(i=0;i<2;i++) pthread_create(&tid[i],NULL,f,NULL);
	for(i=0;i<2;i++) pthread_join(tid[i],NULL);
	printf("First number is a: %d\n",a);
}
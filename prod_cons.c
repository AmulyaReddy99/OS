#include<stdio.h>
#include<pthread.h>
#define BUFFER_SIZE 10
int queue[BUFFER_SIZE],head,tail;
void insert(int x){queue[tail%BUFFER_SIZE]=x; tail++;}
void take(){head++;}

void producer(){
	if(BUFFER_SIZE==n){
		sleep(60);
	}
	else if(BUFFER_SIZE!=0){
		call_consumer();
	}
	insert();
}

void consumer(){
	if(BUFFER_SIZE==0){
		sleep(60);
	}
	take();
}


int main(){
	producer();
	consumer();
}

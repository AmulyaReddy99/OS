#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main(){
	char *s;
	int shmid=shmget(1234,20,IPC_CREAT|0666);
	s=shmat(shmid,NULL,0);
	printf("Enter a msg: \n");
	scanf("%s",s);
}

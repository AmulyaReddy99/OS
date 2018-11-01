#include <stdio.h>
#include <unistd.h>
int main(){
	pid_t pid;
	printf("Parent PID: %d\n",getpid());
	pid=fork();
	printf("Common area 1 accessed by PID: %d\n", getpid());
	if(pid==0) printf("Child PID: %d -> Parent PID: %d\n",getpid(),getppid());
	else if(pid>0) printf("Parent's private area\n");
	else if(pid<0) printf("Error: Cannot create process\n");
	else printf("Error: Unknown\n");
	printf("Common area 2 accessed by PID: %d\n",getpid());
}
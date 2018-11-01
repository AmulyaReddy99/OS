#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	struct stat b;
	if(stat("envi.c",&b)==-1) printf("XXX\n");
	else{
		if(S_ISREG(b.st_mode)) printf("Regular mode\n");
		if(S_ISDIR(b.st_mode)) printf("Directory\n");
		if(!access("envi.c",R_OK)) printf("Readable\n");
		if(!access("envi.c",W_OK)) printf("Writable\n");
		if(!access("envi.c",X_OK)) printf("Executable\n");
	}
}
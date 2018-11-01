#include <stdio.h>
#include<fcntl.h>

int main()
{
	int f1,f2,n=1;
	char b;
	f1=open("envi.c",O_RDONLY);
	f2=open("file",O_WRONLY|O_CREAT,0666);
	if (f1==-1||f2==-1)
		printf("XXX\n");
	else
		while(n=read(f1,&b,1)) 
			write(f2,&b,1);
}
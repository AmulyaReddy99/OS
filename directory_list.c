#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<dirent.h>

int main()
{
	DIR *d;
	struct dirent *s;
	struct stat buf;
	d=opendir("../");
	chdir("Desktop");
	while((s=readdir(d))!=NULL){
		lstat(s->d_name,&buf);
		if(S_ISDIR(buf.st_mode)) printf("%s\n", s->d_name);
	}
}
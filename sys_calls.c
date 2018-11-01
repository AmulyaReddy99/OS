#include <stdio.h>
#include<unistd.h>

int main()
{
	system("\necho \"hi!\"\n");
	system("ls");
	system("cd ../../Desktop");
	system("touch sample.mp4");
	system("open sample.mp4");
	system("rm sample.mp4");
	// char * file="25. Optimization.mp4";
	return 0;
}
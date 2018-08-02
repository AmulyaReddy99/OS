#include<stdio.h>
int fragment[20],blocks[10],files[10],m,n,no_of_blocks,no_of_files,temp,top;
static int block_arr[10],file_arr[10];

void main(){	
	scanf("%d%d",&no_of_blocks,&no_of_files);
	for(m=0;m<no_of_blocks;m++) scanf("%d",&blocks[m]);
	for(m=0;m<no_of_files;m++) scanf("%d",&files[m]);
	for(m=0;m<no_of_files;m++){
		for(n=0;n<no_of_blocks;n++){
			if(block_arr[n]!=1){
				temp=blocks[n]-files[m];
				if(temp>=0){
					if(top<temp){
						file_arr[m]=n; top=temp;
					}
				}
			}
		fragments[m]=top;
		block_arr[file_arr[m]]=1;
		top=0;
		}
	}
	printf("FNo\tFsize\tBNo\tBsize\tFragment");
	for(m=0;m<no_of_files;m++)
		printf("%d\t%d\t%d\t%d\t%d\t\n",m,files[m],file_arr[m],blocks[file_arr[m]],fragments[m]);
}

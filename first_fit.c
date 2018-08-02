#include<stdio.h>
int bsize[10],psize[10],bno,pno,flags[10],allocation[10],i,j;

void main(){
	for(i=0;i<10;i++)
		allocation[i]=-1;
	scanf("%d",&bno);
	for(i=0;i<bno;i++) scanf("%d",&bsize[i]);
	scanf("%d",&pno);
	for(i=0;i<pno;i++) scanf("%d",&psize[i]);
	
	for(i=0;i<pno;i++)
		for(j=0;j<bno;j++)
			if(flag[j]==0 && bsize[j]>=psize[i]){
				allocation[i]=i; flags[j]=1; break;
			}
	printf("\nBNO\tSIZE\tPNO\tSIZE\n");
	for(i=0;i<bno;i++){
		printf("\n%d\t%d\t",i+1,bsize[i]);
		if(flags[i]==1) printf("%d\t%d\t",allocation[i]+1,psize[allocation[i]]);
		else printf("X");
	}
}

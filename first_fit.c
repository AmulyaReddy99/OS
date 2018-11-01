#include<stdio.h>
int bsize[10],psize[10],bno,pno,flags[10],allocation[10],i,j;

void main(){
	scanf("%d%d",&bno, &pno);
	for(i=0;i<bno;i++) scanf("%d",&bsize[i]);
	for(i=0;i<pno;i++) scanf("%d",&psize[i]);
	
	for(i=0;i<pno;i++)
		for(j=0;j<bno;j++)
			if(flags[j]==0 && bsize[j]>=psize[i]){
				allocation[j]=i; flags[j]=1; break;
			}
	printf("\nBNO\tSIZE\tPNO\tSIZE\n");
	for(i=0;i<bno;i++){
		printf("\n%d\t%d\t",i+1,bsize[i]);
		if(flags[i]==1) printf("%d\t%d\t",allocation[i]+1,psize[allocation[i]]);
		else printf("X");
	}
}
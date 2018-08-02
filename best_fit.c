#include<stdio.h>

void main(){
	int fragment[20],b[20],p[20],i,j,nb,np,temp,lowest=9999;
	static int binary[20],parray[20];
	scanf("%d%d",&nb,&np);
	for(i=1;i<=nb;i++) scanf("%d",&b[i]);
	for(i=1;i<=np;i++) scanf("%d",&p[i]);
	
	for(i=1;i<=np;i++){
		for(j=1;j<=nb;j++){
			if(barray[i]!=1){
				temp=b[j]-p[i];
				if(temp>=0)
					if(lowest>temp){
						parray[i]=j;
						lowest=temp;
					}
			}
		}
	fragment[i]=lowest;
	barray[parray[i]]=1;
	lowest=10000;
	}
	printf("PNO\tPsize\tBNO\tBsize\tFragment\n");
	for(i=1;i<=np&&parray[i]!=0;i++)
		printf("%d\t%d\t%d\t%d\t%d\n",i,p[i],parray[i],b[parray[i]],fragment[i]);
}

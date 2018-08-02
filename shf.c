#include<stdio.h>
int i,n,at[10],bt[10],ct[10],tat[10],wt[10],temp,mina=200,minb;
float atat,awt;

void getdata(){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&at[i],&bt[i]);
		if (mina>at[i]) {mina=at[i]; minb=bt[i];}
	}
	int j=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(bt[i]==bt[j] && at[i]<at[j] && i>j){
				temp=bt[j]; bt[j]=bt[i]; bt[i]=temp;
				temp=at[j]; at[j]=at[i]; at[i]=temp;
			}
			else if(bt[i]<bt[j]){
				temp=bt[j]; bt[j]=bt[i]; bt[i]=temp;
				temp=at[j]; at[j]=at[i]; at[i]=temp;
			}
		}
	}
}
void compute(){
	int s=mina+minb;
	for(i=0;i<n;i++){
		if(at[i]!=mina){
			s+=bt[i];
			ct[i]=s;
		}
		else ct[i]=mina+minb;
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
}
void display(){
	for(i=0;i<n;i++){
		printf("%d\t|%d\t|%d\t|%d\t|%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
		atat+=tat[i];
		awt+=wt[i];
	}
	printf("ATAT: %f\n AWT: %f\n",atat/n, awt/n);
}

int main(){
	getdata(); 
	compute(); 
	display();
}

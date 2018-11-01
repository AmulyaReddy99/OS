#include<stdio.h>
int i,j,n,at[10],bt[10],ct[10],tat[10],wt[10],temp;
float atat,awt;
void display(){
	for(i=0;i<n;i++){
		printf("%d\t|%d\t|%d\t|%d\t|%d\t|%d\n",
			i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
		atat+=tat[i];
		awt+=wt[i];
	}
	printf("ATAT: %f\n AWT: %f\n",atat/n, awt/n);
}
void getdata(){
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&at[i],&bt[i]);	
	int j=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(at[i]<at[j]){
				temp=bt[j]; bt[j]=bt[i]; bt[i]=temp;
				temp=at[j]; at[j]=at[i]; at[i]=temp;
			}
		}
	}
}
void compute(){
	ct[0]=at[0]+bt[0]; 
	for(i=1;i<n;i++){ 
		ct[i]=ct[i-1]+bt[i];
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
}
int main(){
	getdata(); 
	compute(); 
	display();
}
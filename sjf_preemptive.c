#include<stdio.h>
int i,j,n,at[10],bt[10],b[10],ct[10],tat[10],wt[10],temp,s,min_i,QUANTA=1,sum=0;
float atat,awt;
void display(){
	for(i=0;i<n;i++){
		printf("%d\t|%d\t|%d\t|%d\t|%d\t|%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
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
	for (i = 0; i < n; i++){ b[i]=bt[i]; sum+=b[i]; }
}
void minimum(){
	int mini=100;
	for(j=0;j<n && at[j]<=s;j++){
		if(b[j]!=0 && mini>b[j]){
			mini=b[j];
			min_i=j; 
		}
	}
}
void compute(){
	s=at[0]+QUANTA; b[0]-=QUANTA; ct[0]=s;
	while(1){
		minimum();
		s+=QUANTA; b[min_i]-=QUANTA;
		ct[min_i]=s;
		if(s>=sum) break;
	}
	for(i=0;i<n;i++){
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
}
int main(){
	getdata(); 
	compute(); 
	display();
}
#include<stdio.h>
int i,j,n,at[10],bt[10],priority[10],b[10],ct[10],tat[10],wt[10],temp,s,max_i,QUANTA=1,sum=0;
float atat,awt;
void display(){
	for(i=0;i<n;i++){
		printf("%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\n",i+1,at[i],bt[i],priority[i],ct[i],tat[i],wt[i]);
		atat+=tat[i];
		awt+=wt[i];
	}
	printf("ATAT: %f\n AWT: %f\n",atat/n, awt/n);
}
void getdata(){
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d",&at[i],&bt[i],&priority[i]);	
	int j=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(at[i]<at[j]){
				temp=bt[j]; bt[j]=bt[i]; bt[i]=temp;
				temp=at[j]; at[j]=at[i]; at[i]=temp;
				temp=priority[j]; priority[j]=priority[i]; priority[i]=temp;
			}
		}
	}
	for (i = 0; i < n; i++) {b[i]=bt[i]; sum+=b[i];}
}
void maximum(){
	int maxi=0;
	for(j=0;j<=s;j++){
		if(b[j]!=0 && maxi<priority[j]){
			maxi=priority[j];
			max_i=j; 
		}
	}
}
void compute(){
	s=at[0]+QUANTA; b[0]-=QUANTA; ct[0]=s;
	while(1){
		maximum();
		s+=QUANTA; b[max_i]-=QUANTA;
		ct[max_i]=s;
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
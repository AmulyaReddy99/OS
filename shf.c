#include<stdio.h>
int i,n,at[10],bt[10],b[10],ct[10],tat[10],wt[10],temp,mina=200,minb;
float atat,awt;

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
	for (i = 0; i < n; i++) b[i]=bt[i];
}
void minimum(){
	int mini=100;
	for(j=0;j<n && j<=s;j++){
		if(b[j]!=0 && mini>b[j]){
			mini=b[j];
			min_i=j; 
		}
	}
}
void compute(){
	s=at[0]+bt[0]; b[0]=0; ct[0]=s;
	for(i=0;i<n;i++){
		minimum();
		s+=b[min_i]; b[min_i]=0;
		ct[min_i]=s;
	}
	for(i=0;i<n;i++){
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

#include<stdio.h>
#include<math.h>

int max_need[10][10],need[10][10],alloc[10][10],n,available[3]={10,5,7};
int check(int k){ return need[k][0]==0 && need[k][1]==0 && need[k][2]==0; }

void remain(int x[10][10]){ 
	for(int i=0;i<n;++i) 
		for(int j=0;j<3;j++) 
			available[j]-=x[i][j]; 
}
int possible(int k){
	int flag=0;
	for (int i=0; i<3; i++)
		if (available[i]-need[k][i]>=0)
			flag++;
	if(flag==3) return 1; else return 0;
}
void calculate(){
	remain(alloc);
	while(1){
		for (int k=0;k<n;k++){
			if(possible(k) && !check(k)) {
				printf("%d ", k);
				for(int i=0;i<3;i++){
					available[i]+=alloc[k][i];
					need[k][i]=0;
				}
			}
		}
		int flag=0;
		for (int i=0;i<n;i++) if(check(i)) flag++;
		if(flag==5) { printf("\nPossible\n"); break; }
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++) scanf("%d",&alloc[i][j]);
		for(int j=0; j<3; j++) scanf("%d",&max_need[i][j]);
		for(int j=0; j<3; j++) need[i][j]=max_need[i][j]-alloc[i][j];
	}
	calculate();
	//display();
}

// void display(){
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<3;j++){
// 			printf("%d ",alloc[i][j]);
// 		}
// 		printf("\t|\t ");
// 		for(int j=0;j<3;j++){
// 			printf("%d ",max_need[i][j]);
// 		}
// 		printf("\t|\t ");
// 		for(int j=0;j<3;j++){
// 			printf("%d ",need[i][j]);
// 		}
// 		printf("\n");
// 	}
// }
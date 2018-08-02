#include<stdio.h>
int i,j,n,at[10],bt[10],b[10],ct[10],tat[10],wt[10],QUANTA=2,temp,s,flag,t,sum;
float atat,awt;

int queue[30]; int head,front;
int empty_q(){ if(head==front) return 1; else return 0;}
void append(int x) { queue[front++]=x; }
int head_el(){ return queue[head]; }
void remove_el(){ head++; }
void print_q(){for(j=head;j<front;j++) printf("%d ",queue[i]);}

void display(){
	printf("\n");
	for(i=0;i<n;i++){
		printf("%d\t|%d\t|%d\t|%d\t|%d\t|%d\n",i+1,at[i],b[i],bt[i],ct[i],tat[i],wt[i]);
		atat+=tat[i];
		awt+=wt[i];
	}
	printf("ATAT: %f\n AWT: %f\n",atat/n, awt/n);
}
void getdata(){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&at[i],&bt[i]);
		//if(QUANTA>bt[i]) QUANTA=bt[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(at[i]<at[j]){
				temp=bt[j]; bt[j]=bt[i]; bt[i]=temp;
				temp=at[j]; at[j]=at[i]; at[i]=temp;
			}
		}
	}
	for(i=0;i<n;i++) {b[i]=bt[i]; sum+=b[i];}
}
//6 0 4 1 5 2 2 3 1 4 6 5 3
void compute(){
	s=at[0]; i=0;
	while(s<=sum || flag==0){
		flag=1;
		printf("%d ",s);
		if(empty_q() && s<=sum){	
			//bt[0]-=QUANTA;
			if(bt[0]>0){
				append(0);
				//ct[i]+=QUANTA;
				s+=QUANTA;
				//i++;
				/*while(at[i]<=s && i<n){ 
					append(i); s+=QUANTA; i++;
				}*/
			}
		}
		else if(!empty_q()) {
			printf(" ---");
			t=head_el(); bt[t]-=QUANTA; 
			ct[t]=s;
			i++;
			while(at[i]<=ct[t] && i<n){
				printf(" -->%d %d ",s,at[i]);
				append(i); s+=QUANTA; i++;
			}
			if(bt[t]<=0) remove_el();
			else { remove_el(); append(t); s+=QUANTA; }
			printf("\nbt=%d c[t]=%d s=%d\n",bt[t],ct[t], s);
			//t=head_el(); bt[t]-=QUANTA; ct[t]+=QUANTA;
		}
		//display();
		//print_q();
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

#include<stdio.h>
int i,j,n,at[10],bt[10],b[10],ct[10],tat[10],wt[10],QUANTA,temp,s,t,sum;
float atat,awt;

int queue[30]; int head,front;
int empty_q(){ if(head==front) return 1; else return 0;}
void append(int x) { queue[front++]=x; }
int head_el(){ return queue[head]; }
void remove_el(){ head++; }
// void print_q(){ printf("\n"); for(j=head;j<front;j++) printf("%d ",queue[j]);}

void display(){
	printf("\n");
	for(i=0;i<n;i++){
		printf("%d\t|%d\t|%d\t|%d\t|%d\t|%d\n",i+1,at[i],b[i],ct[i],tat[i],wt[i]);
		atat+=tat[i];
		awt+=wt[i];
	}
	printf("ATAT: %f\n AWT: %f\n",atat/n, awt/n);
}
void getdata(){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&at[i],&bt[i]);
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
	if(empty_q()){	
		if(bt[0]>0) {printf("%d ",i+1); append(0); s+=QUANTA;	i++;}
	}
	int x=2;
	while(!empty_q()){
		//printf(" %d ",s);
		t=head_el();
		if(bt[t]<QUANTA && bt[t]!=0) { 
			s+=bt[t]; x+=bt[t]-QUANTA; 
			ct[t]=x; bt[t]=0; x+=QUANTA;
		}
		else {bt[t]-=QUANTA; ct[t]=x; x+=QUANTA;} 
		
		while(at[i]<=ct[t] && i<n){
			//printf(" -->%d %d ",s,at[i]);
			printf("%d ",i+1);
			append(i); s+=QUANTA; i++;
		}
		if(bt[t]<=0) remove_el();
		else { remove_el(); append(t); printf("%d ",t+1); s+=QUANTA; }
		//printf("\nbt=%d c[t]=%d s=%d\n",bt[t],ct[t], s);
	}
	for(i=0;i<n;i++){
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-b[i];
	}
}
int main(){
	getdata(); 
	printf("QUANTA: "); scanf("%d",&QUANTA);  
	compute(); 
	display();
}


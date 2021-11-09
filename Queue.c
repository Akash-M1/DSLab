#include<stdio.h>
#include<stdbool.h>
#define size 5
int data[size];
int f=-1;
int r=-1;
bool isEmpty(){
	if(f==-1&&r==-1){
		return true;
	}
	return false;
}
bool isFull(){
	if(r==(size-1)){
		return true;
	}
	return false;
}
void EnQueue(int y){
	if(isFull()){
		printf("Error!! Queue is full");
	}
	else if(isEmpty()){
		f=0;
		r=0;
		data[r]=y;
	}
	else{
		r+=1;
		data[r]=y;
	}
}
int DeQueue(){
	int key;
	if(isEmpty()){
		printf("Error!! Queue is Empty ");
		return 0;
	}
	else if(f==r){
		key=data[r];
		f=-1;
		r=-1;
		return key;
	}
	else{
		key=data[f];
		f++;
		return key;
	}
}
void display(){
    for(int i=f;i<=r;i++){
        printf("%d ",data[i]);
    }
}
int main(){
	int ch,n;
	do{
	    printf("\n1-Enqueue\n");
	    printf("2-DeQueue\n");
	    printf("3-Display\n");
	    printf("4-Exit\n");
	    scanf("%d",&ch);
	    switch(ch){
	        case 1:
	        printf("Enter number of elements you want to enter\n");
	        scanf("%d",&n);
	        printf("Enter the elements of the queue\n");
	        for(int i=0;i<n;i++){
	            int k;
	            scanf("%d",&k);
	            EnQueue(k);
	        }
	        break;
	        case 2:
	        printf("Removing %d from the Queue\n",DeQueue());
	        break;
	        case 3:
	        display();
	        break;
	        case 4:
	        printf("Exiting Successfully\n");
	        break;
	        default:
	        printf("Invalid entery");
	        break;
	    }
	}while(ch!=4);
}
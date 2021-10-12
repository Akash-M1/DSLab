/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#define SIZE 10
bool isEmpty(int *top){
	if(*top == -1){
		return true;
	}
	return false;
}
bool isFull(int *top){
	if(*top==10){
		return true;
	}
	return false;
}
void pop(int a[],int *top){
	if(isEmpty(&top)){
		printf("Stack is empty\n");
		return;
	}
	printf("%d\n",a[top]);
	*top -= 1;
}
void push(int value, int a[], int *top){
	if(isFull(&top)){
		printf("Stack is full\n");
		return;
	}
	*top += 1;
	a[*top]=value;
}
void display(int a[], int *top){
	if(isEmpty(&top)){
		printf("Stack is empty\n");
		return;
	}
	for(int i=*top;i>=0;i--){
		printf("%d ",a[i]);
	}
}
int topelement(int a[],int *top){
	if(isEmpty(&top)){
		printf("Stack is empty\n");
		return 1;
	}
	return a[*top];
}
int input(){
    int value;
    printf("Enter the value\n");
    scanf("%d",&value);
    return value;
}
int main()
{
    int a[SIZE];
    int top=-1;
    int ch,value;
	while(true){
	    printf("Enter the operation to be done\n");
	    printf("1-Push 2-Pop 3-Display 4-TopElement 5-Exit\n");
	    scanf("%d",&ch);
	    switch(ch){
	        case 1:
	        value=input();
	        push(value,a,&top);
	        break;
	        case 2:
	        pop(a,&top);
	        break;
	        case 3:
	        display(a,&top);
	        break;
	        case 4:
	        topelement(a,&top);
	        break;
	        default:
	        exit(0);
	    }
	}
}

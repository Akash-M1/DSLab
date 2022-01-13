#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

struct node *head=NULL;

struct node* createNode(){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->prev=NULL;
	newNode->next=NULL;
	return newNode;
}

int countNode(){
	int count=0;
	struct node *temp=head;
	while(temp!=NULL){
		temp=temp->next;
		count+=1;
	}
	return count;
}

void push(int data){
	struct node *newNode = createNode();
	newNode->data=data;
	if(head==NULL){
		head=newNode;
	}
	else{
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
	}
}

void append(int data){
	struct node *newNode = createNode();
	newNode->data=data;
	if(head==NULL){
		head=newNode;
	}
	else if(head->next==NULL){
		newNode->prev=head;
		head->next=newNode;
	}
	else{
		struct node *temp=head;
		while(temp->next != NULL){
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->prev=temp;
	}
}

void insert(int data,int n){
	struct node *newNode = createNode();
	newNode->data=data;
	if(head==NULL && n!=0){
		printf("\nEntered Position is wrong....TryAgain!!\n");
		return;
	}
	else if(n>countNode()){
		printf("Entered Position is greater than count\n");
		return;
	}
	else{
		struct node *temp=head;
		for(int i = 1; i <n-1 ; i++)
		{
			temp=temp->next;
		}
		newNode->next=temp->next;
		temp->next->prev=newNode;
		temp->next=newNode;
		newNode->prev=temp;
	}
}

void delete(int n){
	if(head==NULL){
		printf("\nInvalid!! list is empty\n");
	}
	else{
		struct node *temp=head;
		while(temp->data!=n && temp->next!=NULL){
			temp=temp->next;
		}
		if(temp->next==NULL){
			printf("\nError!!Value not found\n");
		}
		else{
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);
			printf("\nNode Deleted!!\n");
		}
	}
}

void display(){
	struct node *temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

int main(){
	while(true){
		int ch,n;
		printf("Enter the choice\n");
		printf("1-Push the value\n");
		printf("2-Append the value\n");
		printf("3-Insert the value at specified position\n");
		printf("4-Delete the value\n");
		printf("5-Display the LinkedList\n");
		printf("6-Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			{
				printf("Enter the value to be pushed\n");
				scanf("%d",&n);
				push(n);
				break;
			}
			case 2:
			{
				printf("Enter the value to be Appended\n");
				scanf("%d",&n);
				append(n);
				break;
			}
			case 3:
			{
				int n1;
				printf("Enter the position in which value to be inserted\n");
				scanf("%d",&n1);
				printf("Enter the value to be inserted at that position\n");
				scanf("%d",&n);
				insert(n,n1);
				break;
			}
			case 4:
			{
				printf("Enter the value to be Deleted\n");
				scanf("%d",&n);
				delete(n);
				break;
			}
			case 5:
			{
				printf("Elements in the lists are :");
				display();
				break;
			}
			case 6:
			printf("\n***Thank You***\n");
			exit(0);
			break;
			default:
			printf("\nWrong Choice!!Enter again\n");
			break;
		}
	}
}
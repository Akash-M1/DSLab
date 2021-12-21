#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node* create_node(){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    return newnode;
}
void push(int data){
    struct node *newnode=create_node();
    newnode->data=data;
    if(head==NULL){
        head=newnode;
        return;
    }
    else{
        newnode->next=head;
        head=newnode;
        return;
    }
}

void insertend(int data){
    struct node *newnode=create_node();
    newnode->data=data;
    struct node *temp=head;
    if(head==NULL){
        head=newnode;
        return;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next=newnode;
        return;
    }
}

void insertn(int data, int n){
    struct node *newnode=create_node();
    newnode->data=data;
    struct node *temp=head;
    if(head==NULL){
        head=newnode;
        return;
    }
    else{
        for(int i=1;i<n-1;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        return;
    }
}


void display(){
    struct node *temp=head;
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}
int main(){
    int ch,n,ele;
    while(1)
    {
        printf("\nEnter Options\n");
        printf("1-Inserting at start\n");
        printf("2-Inserting at the end\n");
        printf("3-Inserting at specific position\n");
        printf("4-Display the list\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the element to be inserted at the head\n");
            scanf("%d",&ele);
            push(ele);
            printf("Successfully inserted at the head\n");
            break;
            case 2:
            printf("Enter the element to be inserted at the end\n");
            scanf("%d",&ele);
            insertend(ele);
            printf("Successfully inserted at the end\n");
            break;
            case 3:
            printf("Enter the position in which element to be inserted\n");
            scanf("%d",&n);
            printf("Enter the element to be inserted at %d :",n);
            scanf("%d",&ele);
            insertn(ele,n);
            printf("Successfully inserted at the head\n");
            break;
            case 4:
            printf("Elements in the list are \n");
            display();
            break;
            default:
            exit(0);
        }
    }
    return 0;
}

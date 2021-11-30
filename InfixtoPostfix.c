#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define SIZE 10
char s[SIZE];
int top=-1;
bool isempty(){
    if(top == -1){
        return true;
    }
    return false;
}
void push(char ch){
    s[++top]=ch;
}
char pop(){
    if(isempty()){
        printf("Stack is empty");
    }
    return s[top--];
}
int prior(char op){
    if(op == '^'){
        return 3;
    }
    else if(op=='/' || op=='*'){
        return 2;
    }
    else if(op=='+'||op=='-'){
        return 1;
    }
}
void infixtopostfix(char exp1[], char postfix[]){
    int k=0;
    while((ch=infix[i++])!='\0'){
        if(exp1[i]=='('){
            push(exp1[i]);
        }
        else if(isalnum(exp1[i])){
            postfix[k++]=exp1[i];
        }
        else if(exp1[i]==')'){
            while(exp1[top]!='('){
                postfix[k++]=pop();
            }
            char elem=pop();
        }
        else{
            while(prior(exp1[top])>=prior(exp1[i])){
                postfix[k++]=pop();
            }
            push(exp1[i]);
        }
        while(!isempty()){
            postfix[k++]=pop();
        }
    }
}
int main(){
    char infix[10],postfix[10];
    printf("Please enter the infix expression\n");
    scanf("%s",infix);
    infixtopostfix(infix,postfix);
    printf("Postfix Expression is %s",postfix);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<process.h>
struct node{
    int info;
    struct node *next;
};
typedef struct node Nodetype;
Nodetype *top = NULL;


void push();
void pop();
void display();

int main(){
    int choice;
    while(1){
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
             push();
             break;
            case 2:
             pop();
             break;
            case 3:
             display();
             break;
            case 4:
             printf("exiting from program!!!!");
             exit(0);
            default:
             printf("please enter the correct choice between(1-4)");
        }
    }
    return 0;
}
void push(){
    
    Nodetype *Newnode=(Nodetype*)malloc(sizeof(Nodetype));
    int item;
    printf("Enter the item you wanna insert: ");
    scanf("%d",&item);
    if(top==NULL){
        Newnode->info=item;
        Newnode->next=NULL;
        top=Newnode;
    }
    else{
        Newnode->info=item;
        Newnode->next=top;
        top=Newnode;
    }
}
void pop(){
    Nodetype *temp;
    if(top==NULL){
        printf("stack is empty!!!!\n");
        return ;
    }
    else{
        temp=top;
        top=top->next;
        printf("%d deleted form stack",temp->info);
        free(temp);
    }
}
void display(){
    Nodetype *temp;
    if(top==NULL){
        printf("stack is empty!!!\n");
        return;
    }
    else{
        temp=top;
        printf("the elements of the stack is: \n");
        while(temp!=NULL){
            printf("%d\t",temp->info);
            temp=temp->next;
        }
    }
}

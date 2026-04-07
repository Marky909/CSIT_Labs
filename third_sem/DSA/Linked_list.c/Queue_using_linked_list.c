#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};
typedef struct node Nodetype;
Nodetype *rear=NULL;
Nodetype *front = NULL;

void enqueue();
void dequeue();
void display();

int main(){
    int choice;
    while(1){
        printf("\n1.enqueue\n2.dequeue\n3.Display\n4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
             enqueue();
             break;
            case 2:
             dequeue();
             break;
            case 3:
             display();
             break;
            case 4:
             printf("Exitiing from the program!!!!\n");
            exit(0);
            default:
             printf("please enter the valid choice between(1-4)\n");
        }
    }
    return 0;
}
void enqueue(){
    Nodetype *Newnode=(Nodetype*)malloc(sizeof(Nodetype));
    int item;
    printf("Enter the item you want to insert:");
    scanf("%d",&item);
    if(rear==NULL){
        Newnode->info=item;
        Newnode->next=NULL;
        rear=front=Newnode;
    }
    else{
        Newnode->info=item;
        Newnode->next=NULL;
        rear->next=Newnode;
        rear=Newnode;
    }
}
void dequeue(){
    Nodetype *temp;
    if(front==NULL){
        printf("void deltion as there is no any element!!!!\n");
        return;
    }
    else{
        temp=front;
        front=front->next;
        printf("%d deleted from the queue\n",temp->info);
        free(temp);
    }
}
void display(){
    Nodetype *temp;
    if(front==NULL){
        printf("void deletion!!");
        return;
    }
    else{
        temp=front;
        printf("displaying the element from the QUEUE\n");
        while(temp!=NULL){
            printf("%d\t",temp->info);
            temp=temp->next;
        }
    }
}

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};


struct node* insertAtBegin(struct node *ptr,int x){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=ptr;
    ptr=newnode;
    return ptr;
}


void Display(struct node *ptr ){
    while(ptr!=NULL){
    printf("%d\n",ptr->data);
    ptr=ptr->next;
    }
}


int main()
{
   struct node *head=NULL, *newnode, *temp; 
   int ch;
   do{
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("enter data \n");
   scanf("%d",&newnode->data);
   newnode->next=NULL;
   if(head==NULL){
   head=temp=newnode;
   }
   else{
      temp->next=newnode;
      temp=newnode;
   }
   
   printf("1 for more, 0 for end \n");
   scanf("%d",&ch);
   }while(ch!=0);


   printf("displaying list before insertion\n");
   Display(head);
   
   head=insertAtBegin(head,56);
   
   printf("displaying list after insertion\n");
   Display(head);
  


   return 0;
}
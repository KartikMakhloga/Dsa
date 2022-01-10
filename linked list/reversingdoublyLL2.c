#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node *head,*tail;

void reverse(struct node *head){
    struct node *temp,*nextnode;
    temp=head;
    while(temp!=NULL){
        nextnode=temp->next;
        temp->next=temp->prev;
        temp->prev=nextnode;
        
    }
    nextnode=head;
    head=tail;
    tail=nextnode;
 }

void Display(struct node *ptr ){
    while(ptr!=NULL){
    printf("%d\n",ptr->data);
    ptr=ptr->next;
    }
}

int main()
{
   struct node *newnode, *temp,*prevtemp; 
   head=NULL;
   int ch;
   do{
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("enter data \n");
   scanf("%d",&newnode->data);
   newnode->next=NULL;
   newnode->prev=NULL;
   if(head==NULL){
   head=temp=newnode;
   }
   else{
      temp->next=newnode;
      newnode->prev=temp;
      temp=newnode;
   }
   tail=temp;
   
   
   printf("1 for more, 0 for end \n");
   scanf("%d",&ch);
   }while(ch!=0);

   printf("displaying list before reversing\n");
   Display(head);

   reverse(head);

   printf("displaying list after reversing\n");
   reverse(head);


   
   
   
   
  


   return 0;
}
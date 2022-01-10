#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void deleteAtLast(struct node *ptr){
    
    struct node *q;
    q=ptr;
   
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    while(q->next!=ptr){
        q=q->next;
    }
    
    q->next=NULL;
    free(ptr);
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


   printf("displaying list before deletion\n");
   Display(head);
   
   deleteAtLast(head);
   
   printf("displaying list after deletion\n");
   Display(head);
  

   return 0;
}
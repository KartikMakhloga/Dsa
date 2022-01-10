#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insertAtIndex(struct node *ptr,int x,int index){
     struct node* newnode;
     int i=1;
     newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=x;
     while(i!=index-1){
         ptr=ptr->next;
         i++;
     }
     newnode->next=ptr->next;
     ptr->next=newnode;
     
    
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
   
   insertAtIndex(head,56,3);
   
   printf("displaying list after insertion\n");
   Display(head);
  

   return 0;
}
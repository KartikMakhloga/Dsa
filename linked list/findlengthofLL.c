#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};


void Display(struct node *ptr ){
    int count=0;
    while(ptr!=NULL){
        count++;
    printf("%d\n",ptr->data);
    ptr=ptr->next;
    
    }
    printf("length of linked list is %d",count);
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

   printf("displaying list \n");
   Display(head);
  

   return 0;
}
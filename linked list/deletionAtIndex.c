#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void deleteAtIndex(struct node *ptr,int index){
     struct node *q;
     q=ptr;
     int i=1;
     while(i!=index-1){
         ptr=ptr->next;
         i++;
    }
     i=1;
     while(i!=index){
         q=q->next;
         i++;
     }
    //  for (int i = 0; i < index-1; i++)
    // {
    //     ptr = ptr->next;
    //     q = q->next;
    // }
     
     ptr->next=q->next;
     free(q);
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
   
   deleteAtIndex(head,3);
   
   printf("displaying list after deletion\n");
   Display(head);
  

   return 0;
}
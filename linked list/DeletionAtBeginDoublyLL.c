#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};


struct node* deleteAtBegin(struct node* head){

    struct node* temp;
    temp=head;
    temp->next->prev=NULL;
    head=temp->next;
    free(temp);
    return head;

}
   

void Display(struct node *ptr ){
    while(ptr!=NULL){
    printf("%d\n",ptr->data);
    ptr=ptr->next;
    }
}

int main()
{
   struct node *head=NULL, *newnode, *temp,*prevtemp; 
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
   
   printf("1 for more, 0 for end \n");
   scanf("%d",&ch);
   }while(ch!=0);

   printf("displaying list before insertion\n");
   Display(head);
   
   head=deleteAtBegin(head);
   
   printf("displaying list after insertion\n");
   Display(head);
   
  


   return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* reverse(struct node* head){

    struct node* current,*prev,*nex;
    current=nex=head;
    prev=NULL;
    while(nex!=NULL){
       
        nex=nex->next;
        current->next=prev;
        prev=current;
        current=nex;
       
    }
    head=prev;
        
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

   printf("displaying list before reversing\n");
   Display(head);
   
   head=reverse(head);

   printf("displaying list after reversing\n");
   Display(head);
   
   
   return 0;
}
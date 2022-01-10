#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};


struct node* insertAtLast(struct node* tail,int data){

    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data= data;
    newnode->next=NULL;
    newnode->prev=tail;
    tail->next=newnode;
    tail=newnode;

    return tail;

}


struct node* insertAtBegin(struct node* head,int data){

    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data= data;
    newnode->next=head;
    head->prev=newnode;
    newnode->prev=NULL;
    head=newnode;
    return head;

}

int length(struct node *ptr ){
    int count=0;
    while(ptr!=NULL){
        count++;
    ptr=ptr->next;
    
    }
    return count;
}

struct node* insertAtIndex(struct node* tail,struct node* head,int data,int pos){
    
    struct node* temp;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=data;
    int len=length(head);
    if(pos<=0){
        printf("invalid position ");
        return head;
        
    }
    else if(pos==1){
      head=insertAtBegin(head,data);
      return head;
    }
    else if(pos==len){
      tail=insertAtLast(tail,data);
      return tail;
    }
    else if(pos>=len/2){
        temp=tail;
        int i=len;
       if(i>pos+1){
         temp=temp->prev;
         i--;
       }
       newnode->prev=temp->prev;
       newnode->next=temp;
       temp->prev->next=newnode;
       temp->prev=newnode;
       return head;
    }
    else{
        temp=head;
        int i=1;
        if(i<pos-1){
            temp=temp->next;
            i++;
        }
       newnode->prev=temp->prev;
       newnode->next=temp;
       temp->prev->next=newnode;
       temp->prev=newnode;
       return head;

    }

    

}



   

void Display(struct node *ptr ){
    while(ptr!=NULL){
    printf("%d\n",ptr->data);
    ptr=ptr->next;
    }
}

int main()
{
   struct node *head=NULL, *newnode, *temp,*prevtemp, *tail,*check; 
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

   printf("displaying list before insertion\n");
   Display(head);
   
   head=insertAtIndex(tail,head,54,4);

   
   
   printf("displaying list after insertion\n");
   Display(head);
   
  


   return 0;
}
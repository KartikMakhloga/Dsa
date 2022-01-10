#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *left;
    struct node *right;
};

void postOrder(struct node* root){
       if(root!=NULL){
           
           postOrder(root->left);
           postOrder(root->right);
           printf("%d ", root->data);
       }
}



struct node* createnode(int data){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

int main(){
   struct node*root=createnode(5);
   struct node*p=createnode(9);
   struct node*p1=createnode(7);
   struct node*p2=createnode(3);
   struct node*p3=createnode(8);

   root->left=p;
   root->right=p1;
   p->left=p2;
   p->right=p3;

   postOrder(root);
   return 0;

}




#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *deleteAtLast(struct node *tail)
{

    struct node *temp;
    temp = tail;
    tail = temp->prev;
    temp->prev->next = NULL;

    free(temp);
    return tail;
}

struct node *deleteAtBegin(struct node *head)
{

    struct node *temp;
    temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    free(temp);
    return head;
}

int length(struct node *ptr)
{
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("number of nodes = %d\n", count);
    return count;
}

struct node *deleteAtIndex(struct node *tail, struct node *head, int pos)
{

    struct node *temp,*tempnex;
    int len = length(head);
    if (pos <= 0)
    {
        printf("invalid position ");
        return head;
    }
    else if (pos == 1)
    {
        head = deleteAtBegin(head);
        return head;
    }
    else if (pos == len)
    {
        tail = deleteAtLast(tail);
        return tail;
    }
    else
    {
        
        temp =tempnex= head;
        int i = 1;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        free(temp);
        return head;
    }
}

void Display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head = NULL, *newnode, *temp, *prevtemp, *tail, *check;
    int ch;
    do
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data \n");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        tail = temp;

        printf("1 for more, 0 for end \n");
        scanf("%d", &ch);
    } while (ch != 0);

    int len = length(head);

    printf("displaying list before deletion\n");
    Display(head);

    head = deleteAtIndex(tail, head, 3);

    

    printf("displaying list after deletion\n");
    Display(head);
    

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int data;
    struct node*next;
    struct node*prev;
} node;
typedef struct
{
    node*head;
    node*tail;
}linkedlist;
node*newnode(int x)
{
    node*n=malloc(sizeof(node));
    n->data=x;
    n->next=NULL;
    n->prev=NULL;
    return n;
}
linkedlist*initialize()
{
    linkedlist*l=malloc(sizeof(linkedlist));
    l->head=NULL;
    l->tail=NULL;
    return l;
}
void insertstart(linkedlist*l,int x)
{
    node*n=newnode(x);
    if(l->head==NULL)
    return ;
    else if (l->head->next==l->head)
    {
        n->next=n;
        n->prev=n;
        l->head=n;
        l->tail=n;
    }
    else
    {
        n->next=l->head;
        l->head->prev=n;
        l->head=n;
    }
}
void insertend(linkedlist *l,int x)
{
    node*n=newnode(x);
    if(l->head==NULL)
    return ;
    else if (l->head->next==l->head)
    {
        n->next=n;
        n->prev=n;
        l->head=n;
        l->tail=n;
    }
    else
    {
        l->tail->next=n;
        n->prev=l->tail;
        l->tail=n;
    }

}
void deleteend (linkedlist*l)
{
    node*temp=l->head;
    node *prev;
    if(l->head==NULL)
        return;
    while (temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    l->tail=prev;
    free(temp);
}
void deletestart(linkedlist *l)
{
    node*n=l->head;
    if (l->head==NULL)
        return ;
        else if (l->head->next!=NULL)
        {
            free(l->head);
            l->head=NULL;
            l->tail=NULL;
        } else
        {
            l->head=l->head->next;
            free(n);
            l->tail->next=l->head;
        }
}
void display (linkedlist *l)
{
    if(l->head==NULL)
        return ;
    else
    {
        node*temp=l->head;
        while (temp->next!=l->head)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}
void displaywithdowhile(linkedlist*l)
{
    if (l->head==NULL)
        return ;
    node*n=l->head;
    do
    {
        printf("%d",n->data);
        n=n->next;
    }
    while (n!=l->head);
}
int main()

{
    linkedlist*l=initialize();
    insertstart(l,1);
    insertstart(l,9);
    insertstart(l,6);
    insertend(l,3);
    insertend(l,4);
    insertend(l,5);
    display(l);
    printf("\n");
    displaywithdowhile(l);

    return 0;
}

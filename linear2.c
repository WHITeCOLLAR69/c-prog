#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void append(struct node **q,int num)
{
    struct node *temp,*r;
    if (*q==NULL)
    {
        (*q)=(struct node *)malloc(sizeof(struct node));
        (*q)->data=num;
        (*q)->next=NULL;
        (*q)->prev=NULL;
    }
    else
    {
        temp=*q;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        r=(struct node *)malloc(sizeof(struct node));
        r->data=num;
        r->next=NULL;
        r->prev=temp;
        temp->next=r;
    }
}
void addatbegin(struct node **q,int num)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=*q;
    temp->prev=NULL;
    (*q)->prev=temp;
    *q=temp;
    
}

void display(struct node *q)
{
    struct node *show;
    show=q;
    while (show!=NULL)
    {
        printf("\n %d",show->data);
        show=show->next;
    }
}

int main()
{
    struct node *p=NULL;
    append(&p,1);
    append(&p,3);
    append(&p,4);
    append(&p,6);
    append(&p,9);
    display(p);
    addatbegin(&p,13);
    display(p);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct dnode
{
    struct dnode *prev;
    int data;
    struct dnode *next;
};
void append(struct dnode **q,int data)
{
    struct dnode *temp,*r;
    if (*q==NULL)
    {
        *q=(struct dnode *)malloc(sizeof(struct dnode));
        (*q)->prev=NULL;
        (*q)->data=data;
        (*q)->next=NULL;
    }
    else
    {
        temp=*q;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        r=(struct dnode *)malloc(sizeof(struct dnode));
        r->data=data;
        r->prev=temp;
        r->next=NULL;
        temp->next=r;
    }
}
void display(struct dnode *q)
{
    struct dnode *temp=q;
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
void addafter(struct dnode *q,int data,int pos)
{
    struct dnode *temp,*r;
    temp=q;
    for (int i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    if (temp==NULL)
    {
        printf("entered position is greater than the size of the linked list");
    }
    r=(struct dnode *)malloc(sizeof(struct dnode));
    r->data=data;
    r->next=temp->next;
    temp->next=r;
    temp->next->prev=r;
    r->prev=temp;
}

int main()
{
    struct dnode *ptr;
    ptr=NULL;
    int data,n,pos;
    printf("enter no. of elements to be inserted in the doubly linked list\n");
    scanf("%d",&n);
    for(int i=0;i<=n-1;i++)
    {
        printf("enter the element %d\n",i+1);
        scanf("%d",&data);
        append(&ptr,data);
    }
    printf("inserted linked list is \n");
    display(ptr);
    printf("enter the position you want to insert the element\n");
    scanf("%d",&pos);
    printf("enter the data of that element\n");
    scanf("%d",&data);
    addafter(ptr,data,pos);
    printf("linked list after addition of the element\n");
    display(ptr);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void addafter(struct node *q,int pos,int num)
{
    struct node *temp,*r;
    int i=0;
    temp=q;
    for (i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    r=(struct node *)malloc(sizeof(struct node));
    r->data=num;
    r->next=temp->next;
    temp->next=r;
}
void append(struct node **q,int num)
{
    struct node *temp,*r;
    if (*q==NULL)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=num;
        temp->next=NULL;
        *q=temp;
    }
    else
    {
        temp=*q;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
    r=(struct node*) malloc(sizeof(struct node));
    r->data=num;
    r->next=NULL;
    temp->next=r;
    }
}
void linktrav(struct node* q)
{
    struct node *temp=q;
    while(temp!=NULL)
    {
    printf("%d\n",temp->data);
    temp=temp->next;
    }
}
void delete(struct node *q,int pos)
{
    int i;
    struct node *prev=q;
    for (i=1;i<pos-1;i++)
    {
        prev=prev->next;
    }
    struct node *del=prev->next;
    prev->next=del->next;
    free(del);
} 
void count(struct node *q)
{
    int c=0;
    struct node *temp;
    temp=q;
    while (temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    printf("no. of nodes are %d",c);
}
int main()
{
    struct node *ptr;
    int n,num,i=0;
    int pos;       
    printf("enter no. of elements to be inserted in linked list\n");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        printf("enter element no. %d to be inserted\n",i);
        scanf("%d",&num);
        append(ptr,num);
    }
    linktrav(ptr);
    printf("enter element you want to insert\n");
    scanf("%d",&num);
    printf("enter the position of the element to be insterted\n");
    scanf("%d",&pos);
    addafter(ptr,pos,num);
    printf("linked list after insertion\n");
    linktrav(ptr);
    printf("enter the position of node to be deleted\n");
    scanf("%d",&pos);
    delete(ptr,pos);
    printf("linked list after the element is deleted\n");
    linktrav(ptr);
    count(ptr);
    return 0;
}
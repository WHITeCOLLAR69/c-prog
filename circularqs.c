#include<stdio.h>
#define SIZE 5

void insert();
void delet();
void display();

int queue[SIZE], rear = -1, front = -1, item;

int main()
{
    int ch;

    do
    {
        printf("\n\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                delet();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting the program.\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again...\n");
        }
    } while(1);

    return 0;
}

void insert()
{
    if((front == 0 && rear == SIZE-1) || (front == rear+1))
    {
        printf("\nQueue is full.\n");
    }
    else
    {
        printf("\nEnter ITEM: ");
        scanf("%d", &item);

        if(rear == -1)
        {
            rear = 0;
            front = 0;
        }
        else if(rear == SIZE-1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        queue[rear] = item;
        printf("\nItem inserted: %d\n", item);
    }
}

void delet()
{
    if(front == -1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        item = queue[front];

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if(front == SIZE-1)
        {
            front = 0;
        }
        else
        {
            front++;
        }

        printf("\nItem deleted: %d\n", item);
    }
}

void display()
{
    int i;

    if(front == -1 || front == rear+1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\nQueue elements:\n");

        if(rear >= front)
        {
            for(i = front; i <= rear; i++)
            {
                printf("%d\t", queue[i]);
            }
        }
        else
        {
            for(i = front; i < SIZE; i++)
            {
                printf("%d\t", queue[i]);
            }

            for(i = 0; i <= rear; i++)
            {
                printf("%d\t", queue[i]);
            }
        }

        printf("\n");
    }
}

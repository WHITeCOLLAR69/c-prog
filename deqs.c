#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int q[MAX];
int front = -1;
int rear = -1;

void add_rear();
void add_front();
void delete_rear();
void delete_front();
void display();

int main() {
    int ch;
    
    do {
        printf("\n D-Queue Menu");
        printf("\n--------------");
        printf("\n 1. AddRear");
        printf("\n 2. AddFront");
        printf("\n 3. DeleteRear");
        printf("\n 4. DeleteFront");
        printf("\n 5. Display");
        printf("\n 6. Exit");
        printf("\n--------------");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                add_rear();
                printf("\n Queue after insert at rear");
                display();
                break;
            case 2:
                add_front();
                printf("\n Queue after insert at front");
                display();
                break;
            case 3:
                delete_rear();
                printf("\n Queue after delete at rear");
                display();
                break;
            case 4:
                delete_front();
                printf("\n Queue after delete at front");
                display();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("\n Exiting...\n");
                exit(0);
            default:
                printf("\n Wrong Choice\n");
        }
    } while(ch != 6);

    return 0;
}

void add_rear() {
    int no;
    printf("\n Enter value to insert: ");
    scanf("%d", &no);

    if (rear == MAX - 1) {
        printf("\n Queue is Overflow");
        return;
    }
    
    rear++;
    q[rear] = no;

    if (front == -1)
        front = 0;
}

void add_front() {
    int no;
    printf("\n Enter value to insert: ");
    scanf("%d", &no);

    if (front <= 0) {
        printf("\n Cannot add value at front end");
        return;
    }

    front--;
    q[front] = no;
}

void delete_front() {
    int no;

    if (front == -1) {
        printf("\n Queue is Underflow");
        return;
    }

    no = q[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }

    printf("\n Deleted element is %d", no);
}

void delete_rear() {
    int no;

    if (rear == -1) {
        printf("\n Queue is Underflow");
        return;
    }

    no = q[rear];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        rear--;
    }

    printf("\n Deleted element is %d", no);
}

void display() {
    int i;

    if (front == -1) {
        printf("\n Queue is Underflow");
        return;
    }

    printf("\n Output");
    for (i = front; i <= rear; i++) {
        printf("\n %d", q[i]);
    }
}

#include <stdio.h>
#include <stdlib.h>

/* structure containing a data part and link part */
struct node {
    int data;
    struct node* next;
};

void addcirq(struct node**, struct node**, int);
int delcirq(struct node**, struct node**);
void cirq_display(struct node*);

int main() {
    struct node* front = NULL;
    struct node* rear = NULL;

    int choice, item;
    do {
        printf("\nCircular Queue Operations\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                addcirq(&front, &rear, item);
                break;
            case 2:
                item = delcirq(&front, &rear);
                if (item != -1)
                    printf("Deleted item: %d\n", item);
                break;
            case 3:
                cirq_display(front);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

/* adds a new element at the end of the circular queue */
void addcirq(struct node** f, struct node** r, int item) {
    struct node* q = (struct node*)malloc(sizeof(struct node));
    q->data = item;

    if (*f == NULL) {
        *f = q;
        *r = q;
        (*r)->next = *f;
    }
    else {
        (*r)->next = q;
        *r = q;
        (*r)->next = *f;
    }

    printf("Element %d inserted into the circular queue.\n", item);
}

/* removes an element from the front of the circular queue */
int delcirq(struct node** f, struct node** r) {
    int item;
    struct node* q;

    if (*f == NULL) {
        printf("Circular queue is empty.\n");
        return -1;
    }

    q = *f;
    item = q->data;

    if (*f == *r) {
        *f = NULL;
        *r = NULL;
    }
    else {
        *f = (*f)->next;
        (*r)->next = *f;
    }

    free(q);
    return item;
}

/* displays the elements of the circular queue */
void cirq_display(struct node* f) {
    struct node* temp = f;

    if (f == NULL) {
        printf("Circular queue is empty.\n");
        return;
    }

    printf("Circular Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != f);

    printf("\n");
}

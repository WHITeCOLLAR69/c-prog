#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void append(struct node** q, int num);
void display(struct node* q);
int count(struct node* q);

void append(struct node** q, int num) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;

    if (*q == NULL) {
        *q = temp;
        temp->next = *q;
    } else {
        struct node* current = *q;
        while (current->next != *q) {
            current = current->next;
        }
        current->next = temp;
        temp->next = *q;
    }
}

void display(struct node* q) {
    if (q == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = q;
    int count = 0;

    do {
        printf("%d\t", temp->data);
        temp = temp->next;
        count++;
    } while (temp != q);

    printf("\nTotal number of nodes: %d\n", count);
}

int main() {
    struct node* p = NULL;
    int num, i, n;
    printf("enter no. of elements you want to insert\n");
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        printf("Enter the %dth element ",i);
        scanf("%d", &num);
        append(&p, num);
    }

    printf("\nList after inserting the elements:\n");
    display(p);

    return 0;
}

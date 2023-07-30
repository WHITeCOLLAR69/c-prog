#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX 50

struct postfix
{
    int stack[MAX];
    int top, nn;
    char *s;
};

void initpostfix(struct postfix *);
void setexpr(struct postfix *, char *);
void push(struct postfix *, int);
int pop(struct postfix *);
void calculate(struct postfix *);
void show(struct postfix);

int main()
{
    struct postfix q;
    char expr[MAX];

    initpostfix(&q);

    printf("\nEnter postfix expression to be evaluated: ");
    gets(expr);
    setexpr(&q, expr);
    calculate(&q);
    show(q);

    return 0;
}

void initpostfix(struct postfix *p)
{
    p->top = -1;
}

void setexpr(struct postfix *p, char *str)
{
    p->s = str;
}

void push(struct postfix *p, int item)
{
    if (p->top == MAX - 1)
        printf("\nStack is full.");
    else
    {
        p->top++;
        p->stack[p->top] = item;
    }
}

int pop(struct postfix *p)
{
    int data;
    if (p->top == -1)
    {
        printf("\nStack is empty.");
        return 0;
    }
    data = p->stack[p->top];
    p->top--;
    return data;
}

void calculate(struct postfix *p)
{
    int n1, n2, n3;
    while (*(p->s))
    {
        if (*(p->s) == ' ' || *(p->s) == '\t')
        {
            p->s++;
            continue;
        }
        if (isdigit(*(p->s)))
        {
            p->nn = *(p->s) - '0';
            push(p, p->nn);
        }
        else
        {
            n1 = pop(p);
            n2 = pop(p);
            switch (*(p->s))
            {
                case '+':
                    n3 = n2 + n1;
                    break;
                case '-':
                    n3 = n2 - n1;
                    break;
                case '/':
                    n3 = n2 / n1;
                    break;
                case '*':
                    n3 = n2 * n1;
                    break;
                case '%':
                    n3 = n2 % n1;
                    break;
                case '$':
                    n3 = pow(n2, n1);
                    break;
                default:
                    printf("Unknown operator");
                    exit(1);
            }
            push(p, n3);
        }
        p->s++;
    }
}

void show(struct postfix p)
{
    p.nn = pop(&p);
    printf("Result is: %d", p.nn);
}

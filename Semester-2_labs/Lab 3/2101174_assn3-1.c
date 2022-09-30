#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *stack = NULL, *tail = NULL;

void push(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = stack;
    stack = t;

    if (tail = NULL)
    {
        tail = t;
    }
}

void pop()
{
    stack = stack->next;
}

struct node *printlist(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
void top()
{
    int x = stack->data;
    printf("%d", x);
}
int main()
{
    int x, n;

    printf("How many elements you wanna add?\n");
    scanf("%d", &n);

    while (n != 0)
    {
        printf("Enter Data \n");
        scanf("%d", &x);
        push(x);
        n--;
    }
    printf("The stack looks like\n");
    printlist(stack);
    printf("\n");

    printf("Do You want to add any more number ?\nPrint 1 if yes else 0\n");
    int choice = 0;
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("How many No. you wanna add?\n");
        int no;
        scanf("%d", &no);
        while (no != 0)
        {
            printf("Enter Data \n");
            scanf("%d", &x);
            push(x);
            no--;
        }
    }

    printf("The top element is:\n");
    top();

    printf("\nDo you wanna pop anything?\nPrint 1 if yes else 0\n");
    int choice1 = 0;
    scanf("%d", &choice1);

    if (choice1 == 1)
    {
        printf("How many No. you wanna add?\n");
        int no1;
        scanf("%d", &no1);
        while (no1 != 0)
        {
            pop();
            no1--;
        }
    }
    printf("The Final Stack looks like\n");
    printlist(stack);
    return 0;
}
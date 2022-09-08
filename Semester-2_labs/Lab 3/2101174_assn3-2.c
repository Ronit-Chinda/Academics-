#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

#define MAX 100
int arr[MAX];
int marr[MAX];
int Top1 = -1;
int Top2 = -1;
int min = INT_MAX;
int isEmpty()
{
    if (Top1 == -1)
        return 1;
    else
        return 0;
}

int top()
{
    return arr[Top1];
}
int push2(int x)
{
    if (Top2 != MAX - 1)
    {
        marr[++Top2] = x;
    }
}
int push(int x)
{
    if (Top1 != MAX - 1)
    {
        arr[++Top1] = x;
        if (min >= x)
        {
            min = x;
            push2(min);
        }
    }
}

int pop()
{
    if (!isEmpty())
    {
        if (arr[Top1] == marr[Top2])
            Top2--;
        return arr[Top1--];
    }
}

int isFull()
{
    if (Top1 == MAX - 1)
    {
        printf("stack is full\n");
        return 1;
    }
    else
    {
        printf("stack is not full\n");
        return 0;
    }
}

int findMin()
{
    return marr[Top2];
}

int main()
{
    push(5);
    push(3);
    push(8);
    push(3);
    push(5);
    push(50);
    printf("min value is %d\n", findMin());
    printf("popped value is %d\n", pop());
    printf("popped value is %d\n", pop());
    printf("top value is %d\n", top());
    printf("min value is %d\n", findMin());
    printf("popped value is %d\n", pop());
    printf("popped value is %d\n", pop());
    printf("popped value is %d\n", pop());
    printf("min value is %d\n", findMin());
}
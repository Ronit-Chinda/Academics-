#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node
{
    int data;
    struct Node *next;
};
int count = 0;
int coll = 0;
int temp = 0;

void SortedInsert(struct Node **H, int x)
{

    struct Node *t, *q = NULL, *p = *H;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (*H == NULL)
        *H = t;

    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            count++;
            t->next = *H;
            *H = t;
        }

        else
        {
            count++;
            t->next = q->next;
            q->next = t;
        }
    }
}

int hash(int key, int size)
{
    return key % size;
}

int indextoinsert(int arr[], int index, int size)
{
    while (arr[index] != 0)
    {
        temp++;
        coll++;
        index++;
    }
    return (index % size);
}

void insertarr(int arr[], int size, int key)
{
    int data = hash(key, size);
    int index = indextoinsert(arr, data, size);
    arr[index] = key;
}

void Insert(struct Node *H[], int key, int size)
{
    int index = hash(key, size);
    SortedInsert(&H[index], key);
}

void display_chain(struct Node *temp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Array[%d] -> ", i);
        struct Node *t = temp[i];
        while (t)
        {
            printf("%d ", t->data);
            t = t->next;
        }
        printf("\n");
        printf("-------------\n");
    }
}

int validrandom()
{
    return rand() % 100;
}

void printarray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Array[%d] = ", i);
        printf("%d\n", arr[i]);
        printf("-------------\n");
    }
}

void playgame(int arr[], int size)
{
    struct Node *HT[size];

    for (int i = 0; i < size; i++)
        HT[i] = NULL;

    int hash[size];
    for (int i = 0; i < size; i++)
    {
        hash[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        insertarr(hash, size, arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        Insert(HT, arr[i], size);
    }

    int b;
    printf("Enter the value of B\n");
    scanf("%d", &b);
    int sum, flag = 0;
    int i, j = 0;

    for (i = 0; i < size; i++)
    {
        j = i + 1;
        sum = arr[i];

        while (j < size && sum <= b)
        {
            sum += arr[j];

            if (sum == b)
            {
                printf("\n****************\n");
                printf("Subarray :");
                for (int k = i; k <= j; k++)
                {
                    printf("%d ", arr[k]);
                }
                printf("\n****************\n");
                flag = 1;
            }
            j++;
        }
        if (flag == 1)
        {
            printf("B is the winner\n");
            break;
        }
    }
    if (flag == 0)
    {
        printf("A is the winner\n");
    }
    while (1)
    {
        int choice;
        printf("1 - No Of collisons\n");
        printf("2 - Hash table using linear probing\n");
        printf("3 - Hash table using chaining\n");
        printf("0 - Exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("===================\n");
            printf("The no of collision is : %d", coll);
            printf("\n=================\n");
        }

        else if (choice == 2)
        {
            printarray(hash, size);
        }
        else if (choice == 3)
        {
            display_chain(HT, size);
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }
}
int main()
{
    int choice;
    printf("1 - Question\n");
    printf("2 - Question\n");

    scanf("%d", &choice);

    if (choice == 1)
    {
        // First Question

        int size;
        printf("Enter the prime number\n");
        scanf("%d", &size);

        int array[size];
        struct Node *HT[size];

        for (int i = 0; i < size; i++)
            HT[i] = NULL;

        for (int i = 0; i < size; i++)
        {
            array[i] = 0;
        }

        int x;
        printf("Enter number of keys\n");
        scanf("%d", &x);
        srand(time(0));

        for (int i = 0; i < x; i++)
        {
            int random = validrandom(size);
            Insert(HT, random, size);
            insertarr(array, size, random);
        }

        printf("****************\n");
        printf("Using Chaining");
        printf("\n****************\n");
        printf("The number of collision in chaining is : %d", count);
        printf("\n****************\n");
        display_chain(HT, size);
        printf("****************\n");
        printf("Using linear probing");
        printf("\n****************\n");
        printarray(array, size);
        printf("\n****************\n");
        printf("The number of collision in probing is : %d", temp);
        printf("\n****************\n");
    }

    else if (choice == 2)
    {
        // Second Question

        int n;
        printf("Enter the value of A\n");
        scanf("%d", &n);

        int a[n];
        printf("Enter the integers in array\n");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        playgame(a, n);

        // 2 6 0 9 7 3 1 4 1 10
    }

    else
    {
        printf("Invalid choice\n");
    }

    return 0;
}
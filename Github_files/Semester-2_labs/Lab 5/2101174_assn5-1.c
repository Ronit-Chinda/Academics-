#include<stdio.h>
#include<stdlib.h>

struct queue
{
    struct queue* prev;
    int data;
    struct queue* next;
}*front=NULL,*rear=NULL;

int sizeq(){
    struct queue* p=front;
    int count=0;
    while (p!=NULL)
    {
       count++;
       p=p->next;
    }
    return count; 
}

void insertLast(int data,int size){
    int z=sizeq();
    struct queue* t=(struct queue*)malloc(sizeof(struct queue));
    t->data=data;
    if (z==size)
    {
        printf("Queue is Full\n");
    }
    else{
    if (front==NULL)
    {
        front=t;
        rear=t;
        t->prev=NULL;
        t->next=NULL;

    }

    else
    {
        t->prev=rear;
        t->next=NULL;
        rear->next=t;
        rear=t;
    }
    }
}

int deleteFirst(){
     int x=-1;
     int z=sizeq();
     if (z==0)
     {
         return -1;
     }
     
     else
     {
          x=front->data;
          front=front->next;
          if(front!=NULL)
          front->prev=NULL;
          else
          rear = NULL;
          return x;   
     } 

}

void insertFirst(int data,int size){
      int z=sizeq();
    struct queue* t=(struct queue*)malloc(sizeof(struct queue));
    t->data=data;
    if (z==size)
    {
        printf("Queue is Full\n");
    }
    else{
    if (front==NULL)
    {
        front=t;
        rear=t;
        t->prev=NULL;
        t->next=NULL;

    }

    else
    {
        t->prev=NULL;
        t->next=front;
        front->prev=t;
        front=t;
    }
    }

}
int deleteLast(){
     int x=-1;
     int z=sizeq();
     if (z==0)
     {
         return -1;
     }
     
     else
     {
          x=rear->data;
          rear=rear->prev;
          if(rear!=NULL)
          rear->next=NULL;
          else
          {
              front=NULL;
          }
          
          return x; 
     } 
}

void printList(){
    struct queue * p = front;

    while (p != NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}



int main(){
    int size;
    printf("Enter the size of queue\n");
    scanf("%d",&size);

    while (1)
    {
        printf("0- Exit\n");
        printf("1- InsertLast\n");
        printf("2- InsertFirst\n");
        printf("3- DeleteFirst\n");
        printf("4- DeleteLast\n");
        printf("5- Printlist\n");
        
        int choice;
        printf("Enter choice\n");
        scanf("%d",&choice);
        getchar();
        if (choice==0)
        {
            break;
        }
        else if (choice==1)
        {
            int data;
            printf("Enter Data\n");
            scanf("%d",&data);
            getchar();
            insertLast(data,size);
        }
           else if (choice==2)
        {
            int data;
            printf("Enter Data\n");
            scanf("%d",&data);
            getchar();
            insertFirst(data,size);
        }
        else if (choice==3)
        {
            int x=deleteFirst();
            if (x==-1)
            {
                printf("The Queue is empty\n");
            }

            else
            {
                 printf("The dequeued element is :%d\n",x);
            }

           
        }
         else if (choice==4)
        {
            int x=deleteLast();
            if (x==-1)
            {
                printf("The Queue is empty\n");
            }

            else
            {
                 printf("The dequeued element is :%d\n",x);
            }

           
        }
        
        else if (choice==5)
        {
            printf("The Final Queue is :\n");
            printList();
        }
    }
    
    
    return 0;
}
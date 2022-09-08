#include <stdio.h>
#define s 5
int front=0;
int rear=-1;
int size=0;
int q[s];

int queuesize(){
    return size;
}

int enqueue(int data){
    if(queuesize()<5){
        rear=(rear+1)%s;
        q[rear]=data;
        size++;
    }
    else printf("queue is full\n");
}

int dequeue(){
    if(queuesize()>0){
        printf("%d\n", q[front]);
        front=(front+1)%s;
        size--;
    }
    else{
        printf("queue is empty\n");
    }
}

void display(){
    int temp=size, tf=front;
    while(temp--){
        printf("%d ",q[tf]);
        tf=(tf+1)%s;
    }
    if(size==0) printf("queue is empty");
    printf("\n");
}

int main(){
while (1){
    int t;
    printf("0=exit 1=enque 2=dequeue 3=queuesize\n");
    printf("Enter your choice\n");
    scanf("%d", &t);
    if (t == 1){
        int value;
        printf("enter value to enqueue\n");
        scanf("%d", &value);
        enqueue(value);
        display();
    }
    else if (t == 2){
        dequeue();
        display();
    }
    else if (t == 3){
        printf("%d\n", queuesize());
    }
    else if(t ==0) return 0;
}
}
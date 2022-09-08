#include <stdio.h>
#include <stdlib.h>
#define w 10
#define s 5
int count=0;
// circular queue using array
struct q{
    int front, rear, size;
    int wa[w];
}*waitq;
 
// queue using linked list with circular array
struct qnode{
    int sa[s], front, rear, size;
    struct qnode *next;
}*F=NULL, *R=NULL;

struct qnode *create(){
    struct qnode* temp = (struct qnode*)malloc(sizeof(struct qnode));
    temp->front=temp->size=0;
    temp->rear=s-1;
    temp->next=NULL;
    if(!count){
        F=R=temp;
    } 
    else{
        R->next=temp;
        R=temp;
    } 
    count++; 
    return temp;  
} 

int enqueue(int data){
    if(waitq->size!=w){
        waitq->rear=(waitq->rear+1)%w;
        waitq->wa[waitq->rear]=data;
        waitq->size++;
    }
    else printf("queue is full\n");
}
int dequeue(){
    if(waitq->size){
        int temp=waitq->wa[waitq->front];
        waitq->front=(waitq->front+1)%w;
        waitq->size--;
        return temp;
    }
    else{
        printf("queue is empty\n");
    }
}

int s_enqueue(int data, struct qnode *R1){
    if((R1)->size<s){
        (R1)->rear=((R1)->rear+1)%s;
        (R1)->sa[(R1)->rear]=data;
        (R1)->size++;
    }
}

int s_dequeue(){
    if(F->size){
        int x=F->sa[F->front];
        F->front=(F->front+1)%s;
        F->size--;
        if(F->size==0 && count>1){
            F=F->next;
            count--;
        }
        return x;
    }
    else if(count>1){
        F=F->next;
        count--;
        s_dequeue();
    }
}

void multEnqueue(int x){
    if(R->size!=s){
        s_enqueue(x,R);
    }
    else if(F->size!=s){
        s_enqueue(x,F);
        
    }
    else if(waitq->size!=w){
        enqueue(x);
    }
    else{
        struct qnode* temp = create();
        int i=5;
        while(i--){
            s_enqueue(dequeue(), R);    
        }
        enqueue(x);
    }
}

int multDequeue(){
    if(waitq->size ){
        int x= s_dequeue();
        int data=dequeue(); 
        s_enqueue(data, F);
        printf("dequeued element %d\n", x);
        return x;
    }
    else if(waitq->size ==0 ){
        int x=s_dequeue();
        printf("dequeued element %d\n", x);
        return x;
    }
    else{
        printf("node is empty\n");
    }
}
void s_display(struct qnode *temp){
    int i=temp->size, tf=temp->front;
    while(i--){
        printf("%d ",temp->sa[tf]);
        tf=(tf+1)%s;
    }
    if(temp->size==0) printf("service list is empty\n");
    printf("\n");
}

void display(){
    int temp=waitq->size, tf=waitq->front;
    while(temp--){
        printf("%d ",waitq->wa[tf]);
        tf=(tf+1)%w;
    }
    if(waitq->size==0) printf("queue is empty");
    printf("\n");
}

int st_queue(){
    printf("no of node in service list= %d\n",count );
    struct qnode *temp= F;
    int i=1;
    while(i<=count){
        printf("node %d ---> ", i++);
        s_display(temp);
        temp=temp->next;
    }
    printf("no of elements in wait queue: %d\n", waitq->size);
    printf("wait queue ---> ");
    display();
    printf("the next element will be placed in ");
    if(R->size!=s){
        printf("service queue\n");
    }
    else if(waitq->size!=w){
        printf("wait queue\n");
    }
    else{
        printf("multQueue is full\n");
    }
}

int main(){
    struct q *temp = (struct q*)malloc(sizeof(struct q));
    temp->front=temp->size= 0;
    temp->rear=w-1;
    waitq=temp;
    struct qnode* servq = create();
while (1){
    int t;
    printf("0=exit 1=multEnqueue 2=Multdequeue 3=statusqueue \n");
    printf("Enter your choice\n");
    scanf("%d", &t);
    if (t == 1){
        int test;
        printf("no of values to input: ");
        scanf("%d", &test);
        printf("enter values to enqueue: ");                                 
        while(test--){
            int value;
            scanf("%d", &value);
            multEnqueue(value);
        }
        
    }
    else if (t == 2){
        multDequeue();
    }
    else if (t == 3){
        st_queue();
    }
    else if(t ==0) return 0;
}
}
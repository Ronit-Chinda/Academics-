#include <stdio.h>
#include<stdlib.h>
#include <time.h>

int lcol_count=0, ccol_count=0;

struct node{
    int data;
    struct node *next;
};

struct node *new(int key){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=key;
    temp->next=NULL;
    return temp;
}

void sorted_insert(struct node *cht[], int idx, int key){
    if(cht[idx]==NULL){
        // struct node *node=new(key);
        // cht[idx]=node;
        cht[idx]=new(key);
        //printf("\n\nll%d\n\n ",cht[idx]->data);
        return;
    } 
        //printf("out side \n\nll%d\n\n ",cht[idx]->data);
    
    struct node *temp=cht[idx], *prev=NULL;
    while(temp && temp->data<key){
        //printf("here");
        prev=temp;
        temp=temp->next;
    }
    struct node *t=new(key);
    t->next=temp;
    if(prev==NULL) cht[idx]=t;
    else prev->next=t;
    ccol_count++;
}
// void sorted_insert(struct node **head, int key){
//     if((*head)==NULL){
//         // struct node *node=new(key);
//         // (*head)=node;
//         *head=new(key);
//         printf("\n\nll%d\n\n ",(*head)->data);
//         return;
//     } 
    
//     struct node *temp=(*head), *prev=(*head);
//     while(temp && temp->data<key){
//         printf("here");
//         ccol_count++;
//         prev=temp;
//         temp=temp->next;
//     }
//     struct node *t=new(key);
//     t->next=temp;
//     if((*head)->data>key) (*head)=t;
//     else prev->next=t;
// }

int lhash(int ht[], int n, int key){
    int j=0, i=key%n;
    if(ht[i]!=-1){
        while(ht[i]!=-1){
            lcol_count++;
            j++; i=(key+j)%n;
        }
        return i;
    } 
    else{
        return key%n;
    }
}

int chash(int n, int key){
    return key%n;
}

void insert(int lht[], struct node *cht[], int n){
    srand(time(0));
    int i=rand()%n;
    printf("%d\n",i);
    while(i--){
        int key=rand()%100;
        int idx1=lhash(lht, n, key); 
        lht[idx1]=key;
        int idx2=chash(n, key);
        sorted_insert(cht, idx2, key);
        // sorted_insert(&cht[idx2], key);
    }
}

void display_chain(struct node *temp[], int n){
    for(int i=0; i<n; i++){
        printf("a[%d] -> ", i);
        struct node *t=temp[i];
        while(t){
            printf("%d ", t->data);
            t=t->next;
        }
        printf("\n");
    }
    printf("\n");
}

void display_arr(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("arr[%d]= %d \n", i, arr[i]);
    }
}

int main(){
    printf("enter a prime no: ");
    int n; scanf("%d", &n);
    int lht[n];
    struct node *cht[n];
    for(int i=0; i<n; i++){
        cht[i]=NULL;
        lht[i]=-1;
    }
    insert(lht, cht, n);
    printf("cols in linear hashing %d\n", lcol_count);
    printf("cols in chain hashing %d\n", ccol_count);
    display_chain(cht, n);
    display_arr(lht, n);
}
Conversations
Using 33.25 GB
Programme Policies
Powered by Google
Last account activity: 50 minutes ago
Details

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
} *llist =NULL,*tail=NULL;

void insert_first(int x){
	struct node *t = (struct node*)malloc(sizeof(struct node));
	t->data = x;
	t->next = llist;
	llist = t;
	if(tail ==NULL){tail = t;}
	
} 
int delete_first(){
	int x = llist->data;
	llist = llist->next;
	return x;}
void insert_last(int x){
	struct node *t = (struct node*)malloc(sizeof(struct node));
	t->data = x;
	t->next = NULL;
	tail->next =t;
	tail = t;
	if(llist==NULL){llist=t;}
}
int delete_last(){
	int x = tail->data;
	struct node *last = llist;
	while((last->next)->next !=NULL){
		last=last->next;}
	last->next = NULL;
	tail = last;
return x;}

void swap_ends(){int x = delete_first();
		int y = delete_last();
		insert_first(y);insert_last(x);}
void shift_left(int k){
	
	int x;
	for(int i=0;i<k;i++){
		x = delete_last();
		insert_first(x);
}
}
void printFullList(struct node * main_list) {
  struct node * trav = main_list;
  while (trav != NULL) {
    printf("%d ", trav -> data);
    trav = trav -> next;
  }
  printf("\n");
}

int main(){
	int x;
  
	printf("Enter data:\n");
	scanf("%d",&x);
	insert_first(x);
	printf("Enter data:\n");
	scanf("%d",&x);
	insert_last(x);
	printf("Enter data:\n");
	scanf("%d",&x);
	insert_last(x);
	printf("Enter data:\n");
	scanf("%d",&x);
	insert_last(x);
	printf("Enter data:\n");
	scanf("%d",&x);
	insert_last(x);
    printFullList(llist);
	swap_ends();
    printFullList(llist);
	printf("Shift left by:\n");
	scanf("%d",&x);
	shift_left(x);
    printFullList(llist);
}

#include <stdio.h>
#include <stdlib.h>

int circular(int x , int y){
    if(x<0){return (x+y)%y;}
    else{return x%y;}
}
int isFull(int *front, int *rear, int size){if(circular(*front-1,size)==*rear){return 1;}else{return 0;}}
int isEmpty(int *front, int *rear){if(*front ==-1 && *rear==-1){return 1;}else{return 0;}}

void insertRear(int queue[], int* front, int * rear,int size, int x){
	if(*front==-1 && *rear==-1){
		*front=0;
		*rear=0;
		queue[*rear]=x;
		}
	else if(isFull(front,rear,size)){
		printf("Queue is Full!\n");
		}
	else{
		*rear=circular(*rear+1,size);
		queue[*rear] = x;
		}		
}
void insertFront(int queue[], int* front, int * rear,int size, int x){
	if(*front==-1 && *rear==-1){
		*front=0;
		*rear=0;
		queue[*front]=x;
		}
	else if(isFull(front,rear,size)){
		printf("Queue is Full!\n");
		}
	else{
		*front=circular(*front-1,size);
		queue[*front] = x;
		}		
}

int deleteFront(int queue[], int* front, int * rear,int size){
	if(isEmpty(front,rear)){printf("Queue is Empty!\n");}
	else if(*front==*rear){
		int x =queue[*front];
		*front=-1;
		*rear=-1;
		return x;
	}
	else{
		int x =queue[*front];
		*front=circular((*front+1),size);
		return x;
	}
}

int deleteRear(int queue[], int* front, int * rear,int size){
	if(isEmpty(front,rear)){printf("Queue is Empty!\n");}
	else if(*front==*rear){
		int x =queue[*rear];
		*front=-1;
		*rear=-1;
		return x;
	}
	else{
		int x =queue[*rear];
		*rear=circular(*rear-1,size);
		return x;
	}
}
void stretchoiceQueue(int queue[],int *front,int *rear,int size){
    if(*rear<*front){
        
        for(int i=0;i<size-*front;i++){
            queue[size-(1+i)]=queue[size-(6+i)];
        }
        *front = *front+5;
    }
}

void reduceQueue(int queue[],int *front,int *rear,int *size){
    if(*size>10){
        if(*front-*rear>=6){
            for(int i=*front;i<*size;i++){
                queue[i-5]=queue[i];
            }
            *front = *front-5;
            *size=*size-5;
        }
        else if(*front<*rear){
            int offset = *front;
            while(*front!=*rear){
                queue[*front-offset]=queue[*front];
                (*front)++;             
            }
            queue[*front-offset]=queue[*front];
            *front = 0;
            *rear = *rear-offset;
            *size = *size-5;
        }
        else{printf("Cannot reduce size. Space in Use!\n");}
    }
    else{printf("Minimum allowed size already in use!\n");}
    
}
int printElements(int queue[], int* front, int * rear,int size){
	if(isEmpty(front,rear)){printf("Queue is Empty!\n");}else{
	int i =*front;
	if(*rear>=*front){
		while(i<*rear){
			printf("%d ",queue[i]);
			i=(i+1)%size;
		}
	printf("%d",queue[*rear]);
	}
	else{
		while(i<size){
			printf("%d ",queue[i]);
			i++;
		}
		i=0;
		while(i<=*rear){
			printf("%d ",queue[i]);
			i++;
		}
	}
	printf("\n");	}
}

int main(){
    int bigArray[100];
    int size = 10;
    int frontArray=-1;
    int rearArray=-1;
    while(1){
       
        printf("1 - InsertFront\n");
        printf("2 - InsertRear\n");
        printf("3 - DeleteFront\n");
        printf("4 - DeleteRear\n");
        printf("5 - StretchQueue\n");
        printf("6 - ReduceQueue\n");
        printf("7 - PrintElements\n");
        printf("8 - Exit\n");

        int choice;
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter Data:\n");
            int data;
            scanf("%d",&data);
            insertFront(bigArray,&frontArray,&rearArray,size,data);
            printf("Front : %d\nRear : %d\n",frontArray,rearArray);

        }
        else if(choice==2){
            printf("Enter Data:\n");
            int data;
            scanf("%d",&data);
            insertRear(bigArray,&frontArray,&rearArray,size,data);
            printf("Front : %d\nRear : %d\n",frontArray,rearArray);
           
        }
        else if(choice==3){
            int x = deleteFront(bigArray,&frontArray,&rearArray,size);
            if(x!=-1){
                printf("Dequeued: %d\n",x);
                
            }
            
        }
        else if(choice==4){
            int x = deleteRear(bigArray,&frontArray,&rearArray,size);
            if(x!=-1){printf("Dequeued: %d\n",x);
            
            }
        }
        else if(choice==5){
            size = size+5;
            stretchoiceQueue(bigArray,&frontArray,&rearArray,size);
            
        }
        else if(choice==6){
            reduceQueue(bigArray,&frontArray,&rearArray,&size);
            
        }
        else if(choice==7){
            printElements(bigArray,&frontArray,&rearArray,size);
            
        }
        else if(choice==8){
            break;
        }
        else{
            printf("Invalid choiceoice\n");
        }
    }

}
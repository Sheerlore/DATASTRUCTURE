#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Queue{
    int rear, front;
    int size;
    int *arr;
} Queue;

Queue* createQueue(int size){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue -> rear = -1;
    queue -> front = -1;
    queue -> size = size;
    queue -> arr = (int *)malloc(queue -> size * sizeof(int));
    return queue;
}

int isFull(Queue *q){
    return ((q -> front == 0 && q -> rear == q -> size - 1) ||
    (q -> rear == (q -> front - 1) % (q -> size - 1)));
}

int isEmpty(Queue *q){
    return (q -> front == -1);
}

void enQueue(Queue* q, int value){
    if(isFull(q)){
        printf("\nQueue is Full");
        return;
    }else if(isEmpty(q)){
        q -> front = 0;
        q -> rear = 0;
        q -> arr[q -> rear] = value;
    }else if(q -> rear == q -> size - 1 && q -> front != 0){
        q -> rear = 0;
        q -> arr[q -> rear] = value;
    }else{
        q -> rear = q -> rear + 1;
        q -> arr[q -> rear] = value;
    }
}

int deQueue(Queue* q){
    if(isEmpty(q)){
        printf("\nQueue is Empty");
        return INT_MIN;
    }
    int data = q -> arr[q -> front];
    q -> arr[q -> front] = -1;
    if(q -> front == q -> rear){
        q -> front = -1;
        q -> rear = -1;
    }else if(q -> front == q -> size -1){
        q -> front = 0;
    }else{
        q -> front = q -> front + 1;
    }

    return data;

}

void displayQueue(Queue* q){
    if(isEmpty(q)){
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if(q -> rear >= q -> front){
        for(int i = q -> front; i <= q -> rear; i++){
            printf("%d ", q -> arr[i]);
        }
    }else{
        for(int i = q ->front; i < q ->size; i++){
            printf("%d ", q -> arr[i]);
        }
        for(int i = 0; i <= q -> rear; i++){
            printf("%d ", q ->arr[i]);
        }
    }
}


int main(){
    Queue *q = createQueue(5);
    enQueue(q, 14);
    enQueue(q, 22);
    enQueue(q, 13);
    enQueue(q, -6);
    displayQueue(q);

    printf("\nDeleted value = %d", deQueue(q));
    printf("\nDeleted value = %d", deQueue(q));
    displayQueue(q);

    enQueue(q, 9);
    enQueue(q, 20);
    enQueue(q, 5);
    displayQueue(q);
    enQueue(q, 20);
    printf("\n");
    return 0;

    
}
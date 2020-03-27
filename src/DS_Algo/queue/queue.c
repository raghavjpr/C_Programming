#include"queue.h"

queue* init_queue(int n){
    queue* temp = (queue*)malloc(sizeof(queue));
    temp->capacity = n;
    temp->front = temp->size = 0;
    temp->rear = n-1;
    temp->items = (int*)malloc(n*sizeof(int));
    return temp;
}

int isEmpty(queue* q){
    if(q->size == 0)
        return 1;
    return 0;
}

int isFull(queue* q){
    if(q->size == q->capacity)
        return 1;
    return 0;
}

void enqueue(queue* q,int n){
    if(isFull(q))
        return;
    q->rear = (q->rear + 1) % q->capacity;
    q->items[q->rear] = n;
    (q->size)++;
}

int dequeue(queue* q){
    if(isEmpty(q))
        return;
    int n = q->items[q->front];
    q->front = (q->front + 1) % q->capacity;
    (q->size)--;
    return n;
}

int front(queue* q){  
    if (isEmpty(q))  
        return;  
    return q->items[q->front];  
}

int rear(queue* q){
    if (isEmpty(q))  
        return;  
    return q->items[q->rear];  
}
#include"cqueue.h"

queue* init_queue(int n){
    queue* temp = (queue*)malloc(sizeof(queue));
    temp->front = temp->rear = -1;
    temp->size = n;
    temp->items = (int*)malloc(n*sizeof(int));
    return temp;
}

int isEmpty(queue* q){
    if(q->front == -1)
        return 1;
    return 0;
}

int isFull(queue* q){
    if( ( q->front == 0 && q->rear == q->size - 1 ) || ( q->rear + 1 == q->front ) )
        return 1;
    return 0;
}

void enqueue(queue* q,int n){
    if(isFull(q))
        return;
    else if(q->rear == -1)
        q->rear = q->front = 0;
    else if(q->rear == q->size - 1)
        q->rear = 0;
    else
        (q->rear)++;
    q->items[q->rear] = n;
}

int dequeue(queue* q){
    if(isEmpty(q))
        return;
    int n = q->items[q->front];
    if(q->front == q->rear)
        q->front = q->rear = -1;
    else if(q->front == q->size -1)
        q->front = 0;
    else
        (q->front)++;
    return n;
}
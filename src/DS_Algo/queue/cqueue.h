#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int front,rear,size;
    int *items;     
}queue;

queue* init_queue(int n);
int isEmpty(queue* q);
int isFull(queue* q);
void enqueue(queue* q,int n);
int dequeue(queue* q);
#include "stack.h"

stack* init_stack(int size){
    stack *temp = (stack*)malloc(sizeof(stack));
    temp->maximum = size;
    temp->top = -1;
    temp->items = (int*)malloc((temp->maximum)*sizeof(int));
    return temp;
}

void push(stack *temp,int element){
    temp->items[++temp->top] = element;
}

int pop(stack *temp){
    return temp->items[temp->top--];
}

int peek(stack *temp){
    return temp->items[temp->top];
}

int isEmpty(stack *temp){
    if(temp->top == -1)
        return 1;
    return 0;
    
}

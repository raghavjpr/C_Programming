#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int *items;
    int top;
    int maximum;

}stack;

stack* init_stack(int size);
void push(stack *temp,int element);
int pop(stack *temp);
int peek(stack *temp);
int isEmpty(stack *temp);
#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void inflix_to_postflix(char inflix[]);

int main(){
    char inflix[100];
    scanf("%s",inflix);
    inflix_to_postflix(inflix);
}

int isOperator(char a){
    if((a >='a' && a <='z') || (a >='A' && a <='Z'))
        return 1;
    return 0;
}

int prefrence(char a){
    if(a=='^')
        return 3;
    if(a=='*'||a=='/')
        return 2;
    if(a=='+'||a=='-')
        return 1;
    return 0;
}

void inflix_to_postflix(char inflix[]){
    char postflix[100];
    int p = 0;
    stack *s = init_stack(100);
    for(int i=0; inflix[i]!='\0'; i++){

        if(isOperator(inflix[i]) == 1){
            postflix[p] = inflix[i];
            p++;
        }

        else if(inflix[i] == '(')
            push(s,inflix[i]);
        
        else if(inflix[i] == ')'){
            while (!isEmpty(s) && peek(s) != '('){
                postflix[p] = pop(s);
                p++;
            }
            if(peek(s) == '(')
                pop(s);
        }

        else{
            while (!isEmpty(s) && (prefrence(inflix[i]) <= prefrence(peek(s)))){ 
                postflix[p] = pop(s);
                p++;
            } 
            push(s,inflix[i]);
        }
    }
    while (!isEmpty(s)){
        postflix[p] = pop(s);
        p++;
    }
    postflix[p] = '\0'; 
    printf("%s\n", postflix);
}
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int dest;
    struct Node *next;
}node;

typedef struct List{
    node *head;
}list;

typedef struct Graph{
    int v;
    list* array;
}graph;

node* init_node(int n);
graph* init_graph(int n);
void add_edge(graph* g, int src, int dest);
#include"graph_undirected.h"

node* init_node(int n){
    node* temp = (node*)malloc(sizeof(node));
    temp->dest = n;
    temp->next = NULL;
    return temp;
}

graph* init_graph(int n){
    graph* temp = (graph*)malloc(sizeof(graph));
    temp->v = n;
    temp->array = (list*)malloc(n*sizeof(list));
    for (int i = 0; i < n; ++i) 
        temp->array[i].head = NULL;
    return temp;
}

void add_edge(graph* g, int src, int dest){
    node* temp = init_node(dest);
    temp->next = g->array[src].head;
    g->array[src].head = temp;

    temp = init_node(src);
    temp->next = g->array[dest].head;
    g->array[dest].head = temp;
}

// void printGraph(graph* g){
//     for (int i = 0; i < g->v; ++i){
//         node* pCrawl = g->array[i].head;
//         printf("%d head",i); 
//         while (pCrawl){
//             printf("-> %d", pCrawl->dest);
//             pCrawl = pCrawl->next;
//         }
//         printf("\n");
//     }
// }

// int main(){
//  int V = 5; 
//  graph* g = init_graph(V); 
//  add_edge(g, 0, 1);
//  add_edge(g, 0, 2); 
//  add_edge(g, 0, 4); 
//  add_edge(g, 1, 2); 
//  add_edge(g, 1, 3); 
//  add_edge(g, 1, 4); 
//  add_edge(g, 2, 3); 
//  add_edge(g, 3, 4);
//  printGraph(g);
//  return 0; 
// }
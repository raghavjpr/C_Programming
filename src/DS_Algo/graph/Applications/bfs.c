#include "graph_directed.h"
#include "queue.h"

void DFS(int start , int visited[] , graph* g){
    visited[start] = 1;
    init

    node* i = g->array[start].head;
    while(i){
        start = i->dest;
        if(visited[start]==0)
            DFS(start,visited,g);
        i = i->next;
    }
}

void dfs(graph* g, int V){
    int visited[g->v];
    for(int i=0; i<g->v; i++){
        visited[i] = 0;
    }
    for(int i=0;i<g->v;i++){
        if(visited[i] == 0){
            BFS(V,visited,g);
        }
    }
}

int main() 
{
    int V = 5;
    graph* g = init_graph(5); 
    add_edge(g,0,1); 
    add_edge(g,0,2); 
    add_edge(g,1,2); 
    add_edge(g,2,0); 
    add_edge(g,2,3); 
    add_edge(g,3,3);
    dfs(g,2); 
    return 0; 
} 
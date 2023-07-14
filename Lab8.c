#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int dest;
    struct Node* next;
} Node;

typedef struct List{
    Node *head;
    Node *tail;
} List;

typedef struct Graph{
    int v;
    List* array;
} Graph;

Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int v) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->v = v;
    
    graph->array = (List*)malloc(v * sizeof(List));
 
    for (int i = 0; i < v; i++){
        graph->array[i].head = NULL;
        graph->array[i].tail = NULL;
    }
 
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int matrix[4][4]) {
    Node* newNode = createNode(dest);
    if (graph->array[src].head == NULL) {
        graph->array[src].head = newNode;
        graph->array[src].tail = newNode;
    } else {
        graph->array[src].tail->next = newNode;
        graph->array[src].tail = newNode;
    }
    matrix[src][dest] = 1;
}

void printGraph(Graph* graph, int matrix[4][4]) {
    int vv;
    printf("\nAdjacency List: \n");
    for (vv = 0; vv < graph->v; vv++) {
        Node* node = graph->array[vv].head;
        printf("%d:", vv);
        while (node) {
            printf(" %d ->", node->dest);
            matrix[vv][node->dest] = 1;
            node = node->next;
        }
        printf(" NULL\n");
    }
    printf("\n");
}

int main() {
    int v = 4;
    int matrix[4][4] = {0};
    Graph* graph = createGraph(v);
    addEdge(graph, 0, 1, matrix);
    addEdge(graph, 0, 2, matrix);
    addEdge(graph, 1, 2, matrix);
    addEdge(graph, 2, 0, matrix);
    addEdge(graph, 3, 2, matrix);

    printf("Adjacency Matrix:\n");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // printf("Adjacency List:\n");
    printGraph(graph, matrix);


 
    return 0;
}

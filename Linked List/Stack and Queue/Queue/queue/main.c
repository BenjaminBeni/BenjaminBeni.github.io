#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

typedef struct queue {
    Node *last;
    Node *first;
} Queue;

Queue create_queue(){
    Queue x;
    x.last = NULL;
    x.first = NULL;
    return x;
}

void enqueue(Queue *q, int x){
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = x;
    if(q->last == NULL){
        n->next = NULL;
        q->last = n;
        q->last->prev = NULL;
        q->first = n;
        q->first->prev = NULL;
    }
    else{
        q->last->prev = n;
        n->next = q->last;
        n->prev = NULL;
        q->last = n;
    }
}

int dequeue(Queue *q){
    int x;
    Node *n = q->first;
    x = n->data;
    n->prev->next = NULL;
    q->first = n->prev;
    free(n);
    return x;
}

void print(Queue *q){
    Node *n;
    n = q->first;
    while(n != NULL){
        printf("%d\n", n->data);
        n = n->prev;
    }
}

int main()
{
    Queue q = create_queue();
    int x, i;

    scanf("%d", &x);
    while(x>0){
        scanf("%d", &i);
        enqueue(&q, i);
        x--;
    }
    dequeue(&q);
    dequeue(&q);
    print(&q);
    return 0;
}

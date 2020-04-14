#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

typedef struct queue {
    int head;
    int tail;
    int allowed;
    int el;
    int arr[];
} Queue;

Queue create_queue(int limit){
    Queue x;
    x.head = 0;
    x.tail = 0;
    x.el = 0;
    x.allowed = limit;
    return x;
}

void enqueue(Queue *q, int x){
    q->arr[q->el % q->allowed] = x;
    q->el += 1;
    q->tail += 1;
}

int dequeue(Queue *q){
    int x;
    x = q->arr[q->head];

    q->head += 1;
    q->allowed -= 1;

    return x;
}
/// 1 2 3 4 5 6
/// 1 2 3 4 5 6
/// s 2 3 4 5 s, q allowed = 3
///
void print(Queue *q){
    while(q->tail - q->head > q->allowed){
        printf("Limit exceeded\n");
        q->tail -= 1;
    }
    for(int i = q->head; i < q->tail; i++){
        printf("%d\n", q->arr[i]);
    }
}

int main()
{
    Queue q = create_queue(5);
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

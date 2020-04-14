#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} Node;
typedef struct stack {
    Node *top;
} Stack;

Stack create_stack(){
    Stack x;
    x.top = NULL;
    return x;
}

void push(Stack *s, int x){
    Node *n;
    n = malloc(sizeof(Node));
    n->data = x;
    n->next = NULL;
    if(n != NULL){
        if(s->top == NULL){
             s->top = n;
        }
        else{
             n->next = s->top;
             s->top = n;
        }
    }
}
int pop(Stack *s){
    int x;
    Node *n = s->top;
    x = n->data;
    s->top = n->next;
    free(n);
    return x;
}
void print(Stack *s){
    Node *n = s->top;
    while(n != NULL){
        printf("%d\n", n->data);
        n = n->next;
    }
}

int main()
{
    Stack s = create_stack();
    int x, i;

    scanf("%d", &x);
    while(x>0){
        scanf("%d", &i);
        push(&s, i);
        x--;
    }
    pop(&s);
    pop(&s);
    print(&s);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
    int el;
    int elin;
} Stack;

Stack create_stack(int limit){
    Stack x;
    x.top = NULL;
    x.el = limit;
    x.elin = 0;
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
    s->elin += 1;
}

int pop(Stack *s){
    int x;
    Node *n = s->top;
    x = n->data;
    s->top = n->next;
    free(n);
    s->el -= 1;
    s->elin -= 1;
    return x;
}

void print(Stack *s){
    Node *n = s->top;
    int x = s->elin;
    while(n != NULL){
        if(x > s->el){
             printf("Limit exceeded\n");
        }
        else{
             printf("%d\n", n->data);
        }
        x -= 1;
        n = n->next;
    }
}

int main(){
    Stack s = create_stack(6);
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

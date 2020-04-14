#include <stdio.h>
#include <stdlib.h>

#define and &&

struct node{
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node newNode;

struct list{
    newNode *head;
    newNode *tail;
};
typedef struct list newList;

newList L;
newList L2;
newList L3;

int len(newList *l){
    newNode *n;
    int dim = 0;
    if(l -> head == NULL){
        return -1;
    }
    else{
        n = l->head;
        while(n != NULL){
            dim ++;
            n = n -> next;
        }
        return dim;
    }
}

void printBack(newList *l){
    newNode *n;
    if(l->tail != NULL){
        n = l->tail;
        while(n != NULL){
            printf("%d ", n->data);
            n = n->prev;
        }
    }
    else{
        printf("%s", "List is empty.");
    }
}

void print(newList *l){
    newNode *n;
    if(l->head != NULL){
        n = l->head;
        while(n != NULL){
            printf("%d ", n->data);
            n = n->next;
        }
    }
    else{
        printf("%s", "List is empty.");
    }
}

void push(newList *l, int d){
    newNode *n;
    n = malloc(sizeof(newNode));
    if(n != NULL){
        n->data = d;
        n->next = NULL;
        n->prev = NULL;
        if(l->head == NULL){
            l->head = n;
            l->tail = n;
        }
        else{
            l->head->prev = n;
            n->next = l->head;
            l->head = n;
        }
    }
    else{
        printf("%s", "NOT OK");
    }
}

void add(newList *l, int d){
    newNode *n;
    n = malloc(sizeof(newNode));
    if(n != NULL){
        n->data = d;
        n->next = NULL;
        if(l->head == NULL){
            n->prev = NULL;
            l->head = n;
            l->tail = n;
        }
        else{
            n->prev = l->tail;
            l->tail->next = n;
            l->tail = n;
        }
    }
    else{
        printf("%s", "NOT OK");
    }
}

void insert(newList *l, int d, int poz){
    newNode *n;
    if(l->head == NULL){
        push(&L, d);
    }
    else{
        if(poz == 0){
            push(&L, d);
        }
        else{
            int count = 0;
            n = l->head;
            while(n != NULL){
                count++;
                if(count == poz){
                    break;
                }
                n = n->next;
                if(n == NULL){
                    add(&L, d);
                    return;
                }
            }
            newNode *tmp;
            tmp = malloc(sizeof(newNode));
            tmp->data = d;
            tmp->prev = n;
            tmp->next = n->next;
            n->next = tmp;
        }
    }
}

void del(newList *l, int poz){
    newNode *n;
    if(l->head == NULL){
        return;
    }
    else{
        if(poz == 0){
            l->head = l->head->next;
        }
        else{
            int count = 0;
            n = l->head;
            while(n != NULL){
                if(count == poz){
                    break;
                }
                n = n->next;
                if(n->next == NULL){
                    n->prev->next = NULL;
                    return;
                }
                count++;
            }
            n->prev->next = n->next;
            n->next->prev = n->prev;
        }
    }
}

void retVal(newList *l, int arr[]){
    newNode *n;
    int c = 0;
    if(l->head != NULL){
        n = l->head;
        while(n != NULL){
            arr[c] = n->data;
            c++;
            if(n->next == NULL){
               arr[c] = -1;
            }
            n = n->next;
        }
    }
}

int searchS(newList *l, int val){
    newNode *n;
    int count = 0;
    if(l -> head == NULL){
        printf("%s", "List is empty");
    }
    else{
        n = l -> head;
        while(n != NULL){
            if( n -> data == val ){
                return count;
            }
            else{
                count++;
            }
            n = n -> next;
        }
    }
    return -1;
}

void searchM(newList *l, int val, int arr[], int nr){
    if(nr < 1){
        printf("%s", "The number of values you want to search must be higher then or equal to 1");
    }
    else{
        newNode *n;
        newList *l2 = &L2;
        int count = 0, cnr = 0;
        if(l -> head == NULL){
            printf("%s", "List is empty");
        }
        else{
            n = l -> head;
            while(n != NULL && cnr < nr){
                if(n->data == val){
                    add(&L2, count);
                    cnr++;
                }
            count++;
            n = n -> next;
            }
            retVal(l2,arr);
        }
        l2->head = NULL;
        l2->tail = NULL;
    }
}

newList merge2L(newList *l1, newList *l2){
    newList l;
    l.head = NULL;
    l.tail = NULL;
    newNode *n1 = l1->head;
    newNode *n2 = l2->head;
    while(n2 != NULL and n1 != NULL){
        int x1 = n1->data, x2 = n2->data;
        if(x1 < x2){
            add(&l, x1);
            n1 = n1->next;
        }
        else{
            add(&l, x2);
            n2 = n2->next;
        }
    }
    while(n1 != NULL){
        int x1 = n1 -> data;
        add(&l, x1);
        n1 = n1->next;
    }
    while(n2 != NULL){
        int x2 = n2 -> data;
        add(&l, x2);
        n2 = n2 -> next;
    }
    return l;
}

int main()
{
    int arr[] = {1,3,5,7,9};
    int arr2[] = {0,2,4,5,6,8,5};

    for(int i = 0; i < 5; i++){
        add(&L, arr[i]);
    }

    for(int i = 0; i < 7; i++){
        add(&L3, arr2[i]);
    }

    newList l = merge2L(&L, &L3);
    print(&l);

    /*print(&L);
    printf("\n");

    int array[len(&L)];
    int x = searchS(&L, 5); // First poz of 5
    searchM(&L, 5, array, 3);
    for(int i = 0; array[i] != -1; i++){
        printf("%d ", array[i]);
    }*/
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

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

int len(newList *l);
void printBack(newList *l);
void print(newList *l);
void push(newList *l, int d);
void add(newList *l, int d);
void insert(newList *l, int d, int poz);
void del(newList *l, int poz){
    newNode *n;
    if(l->head == NULL){
        return;
    }
    else{
        if(poz <= 0){
            if(l->head->next == l->head){
                l->head = NULL;
                l->tail = NULL;
            }
            else{
                l->head = l->head->next;
                l->head->prev = l->tail;
                l->tail->next = l->head;
            }
        }
        else if (poz >= len(l)-1){
            if(l->tail == l->head){
                l->head = NULL;
                l->tail = NULL;
            }
            else{
                l->tail = l->tail->prev;
                l->tail->next = l->head;
            }
        }
        else{
            int count = 1;
            n = l->head->next;
            while(n != l->head){
                if(count == poz){
                    n->prev->next = n->next;
                    n->next->prev = n->prev;
                    return;
                }
                n = n->next;
                count++;
            }
        }
    }
}
void retVal(newList *l, int arr[]);
int searchS(newList *l, int val);
void searchM(newList *l, int val, int arr[], int nr);

void joc(newList *l, int k){
    /*
        Corect este codul fara comentariu
        Dar pentru Bonchis
        Ne trebuie x = -1 initial si verificarea (x+1) % k == 0
    */
    int x = -1;
    newNode *n;
    n = l->head;
    int ln = len(l);
    //printf("%d\n\n", ln);
    while(ln > 2){

        if((x+1) % k == 0){
            if(n == l->head){
                l->tail->next = l->head->next;
                l->head = l->head->next;
            }
            else if(n == l->tail){
                n->prev->next = l->head;
                l->head->prev = n->prev;
                l->tail = n->prev;
            }
            else{
                n->prev->next = n->next;
                n->next->prev = n->prev;
            }
            ln -= 1;
        }
        /*if(n->next != NULL){
            printf("%d %d\n", x, ln);
        }*/
        n = n->next;
        x += 1;

    }
    //printf("%d\n\n", ln);
}

int main(){
    int k, n;

    printf("%s", "n = ");
    scanf("%d", &n);
    printf("%s", "k = ");
    scanf("%d", &k);
    int arr[n];

    for(int i = 0; i < n; i++){
        arr[i] = i+1;
        add(&L, arr[i]);
    }
    joc(&L, k);
    printf("\n\n");
    print(&L);

    return 0;
}

int len(newList *l){
    newNode *n;
    int dim = 0;
    if(l -> head == NULL){
        return -1;
    }
    else{
        n = l->head->next;
        dim = 1;
        while(n != l->head){
            dim ++;
            n = n -> next;
        }
    }
    return dim;
}

void printBack(newList *l){
    newNode *n;
    if(l->tail != NULL){
        n = l->tail;
        printf("%d ", n->data);
        n = n->next;
        while(n != l->tail){
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
        printf("%d ", n->data);
        n = n->next;
        while(n != l->head){
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
            l -> head = n;
            l -> tail = n;
            l -> head -> next = l->tail;
            l -> head -> prev = l->tail;
            l -> tail -> next = l->head;
            l -> tail -> prev = l->head;
        }
        else{
            n->prev = l->tail;
            n->next = l->head;
            l->head->prev = n;
            l->head = n;
            l->tail->next = l->head;
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
        n->prev = NULL;
        if(l->head == NULL){
            l -> head = n;
            l -> tail = n;
            l -> head -> next = l->tail;
            l -> head -> prev = l->tail;
            l -> tail -> next = l->head;
            l -> tail -> prev = l->head;
        }
        else{
            n->next = l->head;
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



void retVal(newList *l, int arr[]){
    newNode *n;
    int c = 0;
    if(l->head != NULL){
        n = l->head;
        arr[c] = n->data;
        c++;
        n = n->next;
        while(n != l -> head){
            arr[c] = n->data;
            c++;
            if(n->next == l->head){
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
        if(n->data == val){
            return count;
        }
        else{
            n = n->next;
            while(n != l->head){
                if( n -> data == val ){
                    return count;
                }
                else{
                    count++;
                }
                n = n -> next;
            }
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
            return;
        }
        else{
            n = l -> head;
            if(n->data == val){
                add(&L2, count);
                cnr++;
            }
            n = n->next;
            count += 1;
            while(n != l->head && cnr < nr){
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

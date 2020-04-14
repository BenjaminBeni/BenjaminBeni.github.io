#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int asd = 1;

typedef struct node{
    int id;
    struct node *up;
    struct node *down;
    struct node *right;
    struct node *left;
} newNode;

typedef struct list{
    newNode *head;
    newNode *tail;
    int h;
} newList;

double rn(double x0, double x1){
    return x0 + (x1 - x0) * rand() / ((double) RAND_MAX);
}

void print(newList *L){
    newNode *n = L->head;
    while(n != NULL){
        newNode *m = n->right;
        while(m->right != NULL && m->id > -1){
            if(m->right->id == -1){
                printf("%d\n", m->id);
            }
            else{
                printf("%d --- ", m->id);
            }
            m = m->right;
        }
        n = n->down;
    }
}

newNode *searchTaller(newList *L, newNode *n){
        if(n->up != NULL){
            return n;
        }
        while(n->id != -1){
            n = n->right;
            if(n->up != NULL){
                break;
            }
        }
        return n;
}

newNode *searchTallerLeft(newList *L, newNode *n){
    if(n->up != NULL){
        return n;
    }
    while(n->id != -1){
        n = n -> left;
        if(n->up != NULL){
            break;
        }
    }
    return n;
}

newNode *searchNode(newList *L, int val){
    newNode *n = L->head;
    while(1){
        if(n->right->id == -1){
            if(n->down != NULL){
                n = n->down;
            }
            else{
                break;
            }
        }
        else if(n->right->id < val){
            n = n -> right;
        }
        else{
            if(n->down != NULL){
                n = n ->down;
            }
            else{
                break;
            }
        }
    }
    return n;
}

void newHeadTail(newList *L){
    newNode *k = (newNode *)malloc(sizeof(newNode));
    newNode *p = (newNode *)malloc(sizeof(newNode));

    k->id = -1;
    p->id = -1;

    k->left = NULL;
    k->up = NULL;
    k->down = L->head;
    k->right = p;
    L->head->up = k;
    L->head = k;

    p->left = k;
    p->right = NULL;
    p->up = NULL;
    p->down = L->tail;
    L->tail->up = p;
    L->tail = p;
}

void insertSorted(newList *L, int val){
    newNode *n = (newNode *)malloc(sizeof(newNode));
    newNode *x = searchNode(L, val);
    newNode *y = x->right;
    n->id = val;
    n->down = NULL;
    n->up = NULL;
    n->left = x;
    n->right = y;
    int r, nr = 0;
    ///printf("Upper values = : %d %d %d\n\n", x->id, x->right->id, L->tail->id);

    y->left = n;
    x->right = n;
    ///printf("%d %d %d\n", x->id, n->id, y->id);

    ///printf("Lower values = : %d %d %d %d\n\n", x->id, n->id, y->id, y->right->id);

    r = rand();
    nr++;
    while(r % 2 == 0){
        ///printf("r initial = %g\n\n", r);
        ///printf("%d %d %d\n\n",x->id, n->id, y->id);

        x = searchTallerLeft(L, x);

        if(x == L->head){
            newHeadTail(L);
            L->h++;
            x = x -> up;
        }
        else{
            x = x -> up;
        }

        y = searchTaller(L, y)->up;

        newNode *m = (newNode *)malloc(sizeof(newNode));

        m->id = n->id;
        m->left = x;
        m->right = y;
        m->down = n;
        m->up = NULL;

        n->up = m;
        n = m;

        x->right = m;
        y->left = m;

        nr++;
        ///printf("r final = %g\n\n", r);
        r = rand();
    }
    printf("After round %d , L -> h = %d and The Value %d was promoted %d times.\n\n\n", asd, L->h, val, nr);
    asd++;
}

void init(newList *L){
    newNode *n = (newNode *)malloc(sizeof(newNode));
    newNode *m = (newNode *)malloc(sizeof(newNode));
    n->id = -1;
    n->down = NULL;
    n->up = NULL;
    n->left = NULL;
    n->right = NULL;
    m->id = -1;
    m->down = NULL;
    m->up = NULL;
    m->left = NULL;
    m->right = NULL;
    L->head = n;
    L->tail = m;
    L->tail->left = L->head;
    L->head->right = L->tail;
    L->h = 1;
}

newNode *searchNodeToRemove(newList *L, int val){
    newNode *n = L->head;
    while(n->id != val){
        if(n->right->id == -1){
            if(n->down != NULL){
                n = n->down;
            }
            else{
                break;
            }
        }
        else if(n->right->id < val){
            n = n -> right;
        }
        else if(n->right->id == val){
            n = n -> right;
            while(n->down){
                n = n ->down;
            }
            break;
        }
        else{
            if(n->down != NULL){
                n = n ->down;
            }
            else{
                break;
            }
        }
    }
    return n;
}

void removeItem(newList *L, int val){
    newNode *x = searchNodeToRemove(L, val);
    if(x->right == NULL){
        printf("Nu exista!\n");
    }
    else{
        newNode *lt = x->left;
        newNode *rt = x->right;

        while(x){
            newNode *y = x;
            lt->right = rt;
            rt->left = lt;
            x = x -> up;
            if(y){
                free(y);
            }
            if(lt->up){
                lt = lt->up;
            }
            else{
                lt = searchTallerLeft(L, lt)->up;
            }
            if(rt->up){
                rt = rt->up;
            }
            else{
                rt = searchTaller(L, rt)->up;
            }
        }
    }
}

int main()
{
    srand(time(NULL));

    newList L;
    init(&L);

    int arr[15] = {25,30,10,5,3,102,1,49,95,34,54,38,79,2,20};
    for(int i = 0 ; i < 15; i++){
        insertSorted(&L, arr[i]);
    }

    print(&L);

        removeItem(&L, arr[14]);

    printf("\n");
    printf("\n");

    print(&L);

    /*for(int i = 0; i < 1000000; i++){
        insertSorted(&L, i);
    }
    clock_t start, end, nr, start1, end1;
    for(int i = 0; i < 100; i++){
        start = clock();
        clock_t nr1 = 0;
        for(int j = 0; j < 100000; j++){
            start1 = clock();
            searchNode(&L, (int)rand());
            end1 = clock() - start1;
            nr1 += end1;
        }
        double numar = (double)nr1;
        double ttaken = numar / CLOCKS_PER_SEC;
        printf("\n\nTime taken to search for 100k nodes = %f\n\n", ttaken);
        end = clock() - start;
        nr = nr + end;
    }
    double timetaken = ((double)nr)/CLOCKS_PER_SEC;
    printf("\n\nTime taken = %f", timetaken);*/
    return 0;
}





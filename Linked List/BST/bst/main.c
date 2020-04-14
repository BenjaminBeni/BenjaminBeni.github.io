#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
    //struct node *parent;
} newNode;

typedef struct queue{
    newNode *head;
    newNode *tail;
}newQueue;

typedef struct tree{
    newNode *root;
    int dl;
    int dr;
} newTree;

void addQueue(newQueue *q, newNode *n){
    if(q->head == NULL){
        q->head = n;
        q->tail = n;
    }
    else{
        q->tail->next = n;
        q->tail = n;
    }
}

newQueue *initQueue(){
    newQueue *q;
    q = malloc(sizeof(newQueue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

newNode *pop(newQueue *q){
    newNode *n = q->head;
    q->head = q->head->next;
    return n;
}

newTree *initTree(){
    newTree *tree;
    tree = malloc(sizeof(newTree));
    tree->root = NULL;
    tree->dr = 0;
    tree->dl = 0;
    return tree;
}

newNode *initNode(int k){
    newNode *n;
    n = malloc(sizeof(newNode));
    n->data = k;
    n->left = NULL;
    n->right = NULL;
    n->next = NULL;
    //n->parent = NULL;
    return n;
}

void add(newTree *tree, int k){

    newNode *n = tree->root;
    newNode *node = initNode(k);

    int ok = 0;

    while(n != NULL){
        if(k < n->data){
            if(n->left == NULL){
                n->left = node;
                //node->parent = n;
                ok = 1;
                break;
            }
            else{
                n = n->left;
            }
        }
        else{
            if(n->right == NULL){
                n->right = node;
                //node->parent = n;
                ok = 1;
                break;
            }
            else{
                n = n->right;
            }
        }
    }
    if(ok == 0){
        tree->root = node;
    }
}

void visit(newNode *n){
    printf("%d ",n->data);
}

newNode *searchTree(newTree *tree, int k){
    newNode *n = tree->root;
    while(n != NULL && n->data != k){
        if(k > n->data){
            n = n->right;
        }
        else{
            n = n->left;
        }
    }
    return n;
}

void inTraversal(newNode *n){
    if(n != NULL){
        inTraversal(n->left);
        visit(n);
        inTraversal(n->right);
    }
}

void preTraversal(newNode *n){
    if(n != NULL){
        visit(n);
        preTraversal(n->left);
        preTraversal(n->right);
    }
}

void postTraversal(newNode *n){
    if(n != NULL){
        postTraversal(n->left);
        postTraversal(n->right);
        visit(n);
    }
}

void levelTraversal(newNode *n){
    if(n != NULL){
        newQueue *q = initQueue();
        addQueue(q, n);
        while(q->head != NULL){
            newNode *y = pop(q);
            visit(y);
            if(y->left != NULL){
                addQueue(q, y->left);
            }
            if(y->right != NULL){
                addQueue(q, y->right);
            }
        }
    }
}

void removeNode(newTree *tree, int k){
    newNode *n;
    n = tree->root;
    newNode *p = n;
    assert(n!=NULL);
    int ok = -1;

    while(n != NULL){
        if(n->data == k){
            break;
        }
        else if(k < n->data){
            p = n;
            n = n->left;
            ok = 1;
        }
        else{
            p = n;
            n = n->right;
            ok = 0;
        }
    }

    assert(n != NULL);
    newNode *m;
    newNode *p2;
    if(n->left != NULL){
        p2 = n->left;
        m = n->left;
        while(m->right != NULL){
            p2 = m;
            m = m->right;
        }

        p2->right = (p2 != m) ? m->left : NULL;
        m->right = (m != n->right) ? n->right : NULL;
        m->left = (m != n->left) ? n->left : NULL;
        if(ok == -1){
            tree->root = m;
        }
        else if(ok == 1){
            p->left = m;
        }
        else{
            p->right = m;
        }
    }
    else if(n->right != NULL){
        m = n->right;
        p2 = n->right;
        while(m->left != NULL){
            p2 = m;
            m = m->left;
        }
        p2->left = (p2 != m) ? m->right : NULL;
        m->right = (m != n->right) ? n->right : NULL;
        m->left = (m != n->left) ? n->left : NULL;
        if(ok == -1){
            tree->root = m;
        }
        else if(ok == 1){
            p->left = m;
        }
        else{
            p->right = m;
        }
    }
    else{
        if(ok == -1){
            tree->root = NULL;
        }
        else if(ok == 1){
            p->left = NULL;
        }
        else{
            p->right = NULL;
        }
    }
    free(n);
}

int main(){
    newTree *tree = initTree();
    int a[] = {9,6,12,8,11,24,42,5,7,3};
    for(int i = 0; i < 10; i++){
        add(tree, a[i]);
    }
    printf("In-order traversal = ");
    inTraversal(tree->root);
    printf("\n");
    printf("Pre-order traversal = ");
    preTraversal(tree->root);
    printf("\n");
    printf("Post-order traversal = ");
    postTraversal(tree->root);
    printf("\n");
    printf("Level traversal = ");
    levelTraversal(tree->root);
    printf("\n");
    printf("After removing node 8 = ");
    removeNode(tree, 8);
    inTraversal(tree->root);
    printf("\n");
    printf("After removing node 9 = ");
    removeNode(tree, 9);
    inTraversal(tree->root);
    printf("\n");
    printf("NEW ROOT = ");
    visit(tree->root);
    ///removeNode(tree, 876);
    return 0;
}

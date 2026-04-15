#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* lchild;
    int data;
    struct Node* rchild;
} Node;

Node *root = NULL;

void insert(int key){
    Node* curr = root;
    Node* parent = NULL;
    
    if(!root){
        Node* inserted = malloc(sizeof(Node));
        inserted->data = key;
        inserted->lchild = inserted->rchild = NULL;
        root = inserted;
        return;
    }
    
    while(curr){
        parent = curr;
        if(key < curr->data)
            curr = curr->lchild;
        else
            curr = curr->rchild;
    }
    
    Node* inserted = malloc(sizeof(Node));
    inserted->data = key;
    inserted->lchild = inserted->rchild = NULL;
    
    if(key < parent->data)
        parent->lchild = inserted;
    else
        parent->rchild = inserted;
}

void inorder (Node* tree){
    if(tree){
        inorder(tree->lchild);
        printf("%d ", tree->data);
        inorder(tree->rchild);
    }
}

Node* search (int key){
    Node* t = root;
    while(t){
        if(key == t->data)
            return t;
        else if(key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    
    return t;
}

int main(void){
    
    insert(10);
    insert(5);
    insert (20);
    insert(8);
    insert(30);
    
    inorder(root);
    printf("\n");
    
    
    printf("Searching for 30: ");
    if(search(30))
        printf("30 was found.\n");
    else
        printf("30 was not found.\n");
    
    printf("Searching for 99: ");
    if(search(99))
        printf("99 was found.\n");
    else
        printf("99 was not found.\n");
}
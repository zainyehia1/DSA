#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Linked List
typedef struct Node{
    int data;
    struct Node* next;
} Node;

//Stack
typedef struct Stack {
    Node* top;
} Stack;

void create(Stack* st){
    st->top = NULL;
}

bool isEmpty(Stack st){
    return st.top == NULL;
}

bool push(Stack* st, int val){
    Node* t = malloc(sizeof(Node));
    if(!t){
        printf("Stack overflow!");
        return false;
    }
    
    t->data = val;
    t->next = st->top;
    st->top = t;
    
    return true;
}

int pop(Stack* st){
    int x = -1;
    if(isEmpty(*st)){
        printf("Stack is empty!");
        return x;
    }
    
    Node* t = st->top;
    st->top = st->top->next;
    
    x = t->data;
    
    free(t);
    t = NULL;
    
    return x;
}

int peek(Stack st, int pos){
    Node* t = st.top;
    for(int i = 0; t && i < pos; i++){
        t = t->next;
    }
    
    if(t) return t->data;
    
    return -1;
}

int stack_top(Stack st){
    if(!isEmpty(st)) return st.top->data;
    
    return -1;
}

void display(Stack st){
    Node* t = st.top;
    
    printf("Stack:\n");
    while(t != NULL){
        printf("%d\n", t->data);
        t = t->next;   
    }
}

int main(void){
    
    Stack st;
    create(&st);
    
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    
    display(st);
    
    printf("Top: %d\n", stack_top(st));
    pop(&st);
    
    display(st);
    
    printf("Peek 2: %d\n", peek(st, 2));
    
    return 0;
}
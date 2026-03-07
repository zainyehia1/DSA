#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int size;
    int top;
    int* s;
} Stack;

void create(Stack* st){
    printf("Enter stack size: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = malloc(st->size * sizeof(int));
}

void display(Stack st){
    printf("Stack:\n");
    for (int i = st.top; i >= 0; i--){
        printf("%d\n", st.s[i]);
    }
}

//Stack funcs
bool isFull(Stack st){        
    return (st.top == st.size - 1);
}

bool isEmpty(Stack st){
    return (st.top == -1);
}

bool push(Stack *st, int val){
    if(isFull(*st)){
        printf("Stack Overflow!\n");
        return false;
    }
    
    st->s[st->top + 1] = val;
    st->top++;    
    return true;
}

int pop(Stack *st){
    if(isEmpty(*st)){
        printf("Stack is empty\n");
        return -1;
    }
    
    
    st->top--;
    return st->s[st->top + 1];
}

int peek(Stack st, int pos){
    if(isEmpty(st)){
        printf("Stack is empty\n");
        return -1;
    }
    
    int index = st.top - pos + 1;
    
    return st.s[index];
}

int stack_top(Stack st){
    if(!isEmpty(st))
        return st.s[st.top];
}

int main(void){
    Stack st;
    create(&st);
    
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    display(st);
    printf("\n");
    
    // printf("%d \n", pop(&st));
    // printf("%d \n", pop(&st));
    // printf("%d \n", pop(&st));
    // printf("%d \n", pop(&st));
    
    // display(st);
    printf("%d \n", peek(st, 3));
    printf("%d \n", peek(st, 2));
    printf("%d \n", peek(st, 1));
    
    printf("Stack top: %d\n", stack_top(st));
    
    printf("Is Empty? %s\n", isEmpty(st));
    printf("Is Full? %s\n", isFull(st));
    
    printf("Empty spaces: %d\n", st.size - st.top - 1);
    return 0;
}
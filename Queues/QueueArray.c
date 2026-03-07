#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct{
    int size;
    int front;
    int rear;
    int* Q;
} Queue;

void create(Queue* q, int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = malloc(q->size * sizeof(int));
}

bool isEmpty(Queue q){
    return q.front == q.rear;
}

bool isFull(Queue q){
    return q.rear == q.size - 1;
}

bool enqueue(Queue* q, int val){
    if(isFull(*q)){
        printf("Queue is Full!\n");
        return false;
    }
    
    q->Q[++q->rear] = val;
    return true;
}

int dequeue(Queue* q){
    if(isEmpty(*q)){
        printf("Queue is empty!\n");
        return -1;
    }
    
    return q->Q[++q->front];
}

int first(Queue q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }
    
    return q.Q[q.front + 1];
}

int last(Queue q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }
    
    return q.Q[q.rear];
}

void display(Queue q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue: ");
    for(int i = q.front + 1; i < q.rear; i++){
        printf("%d, ", q.Q[i]);
    }
    printf("%d.\n", q.Q[q.rear]);  
}

int main(void){
    Queue q;
    create(&q, 5);
    
    // Test isEmpty on empty queue
    printf("isEmpty (expected true): %s\n", isEmpty(q) ? "true" : "false");
    
    // Test enqueue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Enqueued 10, 20, 30\n");
    display(q);
    
    // Test isEmpty on non-empty queue
    printf("isEmpty (expected false): %s\n", isEmpty(q) ? "true" : "false");
    
    // Test first and last
    printf("first (expected 10): %d\n", first(q));
    printf("last (expected 30): %d\n", last(q));
    
    // Test dequeue
    printf("dequeue (expected 10): %d\n", dequeue(&q));
    printf("dequeue (expected 20): %d\n", dequeue(&q));
    display(q);
    
    // Test isFull
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    printf("isFull (expected true): %s\n", isFull(q) ? "true" : "false");
    enqueue(&q, 70); // should print overflow message
    
    // Test dequeue on empty queue
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q); // should print empty message
    return 0;
}
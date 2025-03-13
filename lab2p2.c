#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *stack1;  
    int *stack2;  
    int size1;    
    int size2;    
    int maxSize;  
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->maxSize = 100; 
    q->stack1 = (int*)malloc(q->maxSize * sizeof(int));
    q->stack2 = (int*)malloc(q->maxSize * sizeof(int));
    q->size1 = 0;
    q->size2 = 0;
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[obj->size1++] = x;  
}

int myQueuePop(MyQueue* obj) {
    if (obj->size2 == 0) { 
        while (obj->size1 > 0) {
            obj->stack2[obj->size2++] = obj->stack1[--obj->size1];
        }
    }
    
    if (obj->size2 == 0) return -1;
    
    return obj->stack2[--obj->size2]; 
}

int myQueuePeek(MyQueue* obj) {
    if (obj->size2 == 0) {  
        while (obj->size1 > 0) {
            obj->stack2[obj->size2++] = obj->stack1[--obj->size1];
        }
    }

    if (obj->size2 == 0) return -1; 

    return obj->stack2[obj->size2 - 1]; 
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->size1 == 0 && obj->size2 == 0; 
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *queue1;
    int *queue2;
    int size1, size2;
    int capacity;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->capacity = 100;  // Arbitrary max size
    stack->queue1 = (int*)malloc(stack->capacity * sizeof(int));
    stack->queue2 = (int*)malloc(stack->capacity * sizeof(int));
    stack->size1 = 0;
    stack->size2 = 0;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->queue1[obj->size1++] = x;  // Add new element to queue1
}

int myStackPop(MyStack* obj) {
    if (obj->size1 == 0) return -1;  // Stack is empty
    
    // Move elements to queue2 except last one
    while (obj->size1 > 1) {
        obj->queue2[obj->size2++] = obj->queue1[--obj->size1];
    }

    int popped = obj->queue1[--obj->size1]; // Last element

    // Swap queue1 and queue2
    int* temp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = temp;

    obj->size1 = obj->size2;
    obj->size2 = 0;  // Reset queue2

    return popped;
}

int myStackTop(MyStack* obj) {
    if (obj->size1 == 0) return -1;
    
    while (obj->size1 > 1) {
        obj->queue2[obj->size2++] = obj->queue1[--obj->size1];
    }

    int top = obj->queue1[obj->size1 - 1]; // Last element

    obj->queue2[obj->size2++] = obj->queue1[--obj->size1];  // Keep it

    // Swap queue1 and queue2
    int* temp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = temp;

    obj->size1 = obj->size2;
    obj->size2 = 0;  // Reset queue2

    return top;
}

bool myStackEmpty(MyStack* obj) {
    return obj->size1 == 0;
}

void myStackFree(MyStack* obj) {
    free(obj->queue1);
    free(obj->queue2);
    free(obj);
}

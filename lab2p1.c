typedef struct {
    int data[100]; 
    int front, rear, size;
} Queue;


void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

bool isEmpty(Queue *q) {
    return q->size == 0;
}


void enqueue(Queue *q, int x) {
    q->data[q->rear++] = x;
    q->size++;
}


int dequeue(Queue *q) {
    if (!isEmpty(q)) {
        q->size--;
        return q->data[q->front++];
    }
    return -1; 
}


typedef struct {
    Queue q1, q2;
} MyStack;


MyStack* myStackCreate() {
    MyStack *stack = (MyStack*)malloc(sizeof(MyStack));
    initQueue(&stack->q1);
    initQueue(&stack->q2);
    return stack;
}


void myStackPush(MyStack* obj, int x) {
    enqueue(&obj->q1, x);
}


int myStackPop(MyStack* obj) {
    while (obj->q1.size > 1) {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }
    int topElement = dequeue(&obj->q1);
    Queue temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    return topElement;
}


int myStackTop(MyStack* obj) {
    while (obj->q1.size > 1) {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }
    int topElement = dequeue(&obj->q1);
    enqueue(&obj->q2, topElement);
    Queue temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    return topElement;
}

bool myStackEmpty(MyStack* obj) {
    return isEmpty(&obj->q1);
}


void myStackFree(MyStack* obj) {
    free(obj);
}

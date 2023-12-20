#include <stdlib.h>

typedef struct {
    int* data;
    int maxSize;
    int head;
    int tail;
    int size;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k);
int myCircularQueueEnQueue(MyCircularQueue* obj, int value);
int myCircularQueueDeQueue(MyCircularQueue* obj);
int myCircularQueueFront(MyCircularQueue* obj);
int myCircularQueueRear(MyCircularQueue* obj);
int myCircularQueueIsEmpty(MyCircularQueue* obj);
int myCircularQueueIsFull(MyCircularQueue* obj);
void myCircularQueueFree(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->data = (int*)malloc(sizeof(int) * k);
    obj->maxSize = k;
    obj->head = -1;
    obj->tail = -1;
    obj->size = 0;
    return obj;
}

int myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        return 0;
    }

    if (myCircularQueueIsEmpty(obj)) {
        obj->head = 0;
    }

    obj->tail = (obj->tail + 1) % obj->maxSize;
    obj->data[obj->tail] = value;
    obj->size++;

    return 1;
}

int myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return 0;
    }

    if (obj->head == obj->tail) {
        obj->head = -1;
        obj->tail = -1;
    } else {
        obj->head = (obj->head + 1) % obj->maxSize;
    }

    obj->size--;

    return 1;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    return myCircularQueueIsEmpty(obj) ? -1 : obj->data[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    return myCircularQueueIsEmpty(obj) ? -1 : obj->data[obj->tail];
}

int myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

int myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->maxSize;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}

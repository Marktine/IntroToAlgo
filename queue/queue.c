#include "queue.h"
#include "stdlib.h"

// create new queue
static struct queue* newQueue(int capacity) {
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    q->rear = capacity - 1;
    q->array = (int *)malloc(capacity * sizeof(int));
    return q;
}

// check if queue is full
static int isFull(struct queue* this) {
    return (this->size == this->capacity);
}

// check if queue is empty
static int isEmpty(struct queue* this) {
    return (this->size == 0);
}

static int getSize(struct queue* this) {
    return this->size;
}

// add an item to the queue, returns new queue size
static int enqueue(struct queue* this, int data) {
    if (queue.isEmpty(this)){
        return 0;
    }
    this->rear = (this->rear + 1) % this->capacity;
    this->array[this->rear] = data;
    this->size = this->size + 1;
    return this->size;
}

// remove an item from the queue, returns removed item
static int dequeue(struct queue* this) {
    if (queue.isEmpty(this)) {
        return 0;
    }
    int item = this->array[this->front];
    this->front = (this->front + 1) % this->capacity;
    this->size = this->size - 1;
    return item;
}

const struct queue_class queue = {
    .newQueue=&newQueue,
    .isFull=&isFull,
    .isEmpty=&isEmpty,
    .getSize=&getSize, 
    .enqueue=&enqueue,
    .dequeue=&dequeue,
}
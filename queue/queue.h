#ifndef H_QUEUE
#define H_QUEUE
    struct queue {
        // private:
        int front, rear, size;
        unsigned int capacity;
        int* array;
    };
    extern const struct queue_class {
        // public:
        struct queue* (*newQueue)(unsigned int capacity);
        int (*isFull)(struct queue* this);
        int (*isEmpty)(struct queue* this);
        int (*getSize)(struct queue* this);
        int (*enqueue)(struct queue* this, int data);
        int (*dequeue)(struct queue* this);
        int (*front)(struct queue* this);
        int (*rear)(struct queue* this);
    } queue;
#endif
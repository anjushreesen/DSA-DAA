#ifndef Queue_h
#define Queue_h

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

// This Queue will hold pointers of type Node
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q; //pointer to an array in the heap, which will store pointers of type Node
};

void create(struct Queue *q, int sz)
{
    q->size = sz;
    q->front = q->rear = 0; //In Circular Queue, front and rear start at 0
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is full\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node *dequeue(struct Queue *q)
{
    struct Node *x = NULL;

    if (q->front == q->rear)
        printf("Queue is empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}

#endif /* Queue_h */
// Queue is a linear structure which follows a particular order in which the operations are performed.
// The order is First In First Out (FIFO).  A good example of queue is any queue of
// consumers for a resource where the consumer that came first is served first. 
// The difference between stacks and queues is in removing.
// In a stack we remove the item the most recently added; in
// a queue, we remove the item the least recently added.

#include<bits/stdc++.h>
using namespace std;

class Queue
{
    public:
        int front, rear, size, capacity;
        int *arr;
};

Queue* createQueue(int capacity)
{
    Queue* queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;
 
    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->arr = new int[queue->capacity];
    return queue;
}

// Queue is full when size
// becomes equal to the capacity
int isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}
 
// Queue is empty when size is 0
int isEmpty(Queue* queue)
{
    return (queue->size == 0);
}
 
// Function to add an item to the queue.
// It changes rear and size
void enqueue(Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size = queue->size + 1;
    cout << item << " enqueued to queue\n";
}


// Function to remove an item from queue.
// It changes front and size
int dequeue(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
 
// Function to get front of queue
int front(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->front];
}
 
// Function to get rear of queue
int rear(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->rear];
}

int main(int argc, char const *argv[])
{

    Queue* queue = createQueue(1000);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
 
    cout << dequeue(queue)
         << " dequeued from queue\n";
 
    cout << "Front item is "
         << front(queue) << endl;
    cout << "Rear item is "
         << rear(queue) << endl;
     
    return 0;
}


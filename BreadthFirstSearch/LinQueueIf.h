// Initializes the queue with size n
void initialize(queueADT *Q, int n);
// Checks if the queue is full
int isFull(queueADT *Q);
// Checks if the queue is empty
int isEmpty(queueADT *Q);
// Enqueues x to the queue at the rear
void enqueue(queueADT *Q, int x);
// Dequeues the first element in the queue
int dequeue(queueADT *Q);
// Displays the queue
void displayQ(queueADT *Q);
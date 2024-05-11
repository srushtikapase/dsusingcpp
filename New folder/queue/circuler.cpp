#include <iostream>

using namespace std;

#define SIZE 5 // Size of the circular queue

class CircularQueue {
private:
    int front, rear;
    int items[SIZE];

public:
    CircularQueue() {
        front = rear = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to enqueue an element
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        }
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        cout << "Enqueued " << element << " to the queue." << endl;
    }

    // Function to dequeue an element
    int dequeue() {
        int element;
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        element = items[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
        cout << "Dequeued " << element << " from the queue." << endl;
        return element;
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);

    cq.dequeue();
    cq.enqueue(4);
    cq.dequeue();
    cq.dequeue();

    return 0;
}

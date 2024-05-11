#include <iostream>
#include <queue>

using namespace std;

class Queue {
private:
    queue<int> data;

public:
    // Function to enqueue (add) an item to the queue
    void enqueue(int item) {
        data.push(item);
        cout << "Enqueued " << item << " to the queue." << endl;
    }

    // Function to dequeue (remove) an item from the queue
    int dequeue() {
        if (data.empty()) {
            cout << "Queue is empty, cannot dequeue." << endl;
            return -1; // Return a default value indicating failure
        } else {
            int dequeued_item = data.front();
            data.pop();
            cout << "Dequeued " << dequeued_item << " from the queue." << endl;
            return dequeued_item;
        }
    }
};

int main() {
    // Create a queue object
    Queue queue;

    // Example usage
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.dequeue();
    queue.dequeue();

    return 0;
}

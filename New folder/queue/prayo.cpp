#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Create a priority queue
    priority_queue<int> pq;

    // Enqueue elements
    pq.push(3);
    pq.push(1);
    pq.push(2);

    // Dequeue elements and print
    while (!pq.empty()) {
        cout << pq.top() << " "; // Print the top element
        pq.pop(); // Remove the top element
    }

    return 0;
}

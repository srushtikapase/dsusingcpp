#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Create a standard queue
    queue<int> q;

    // Enqueue elements
    q.push(1);
    q.push(2);
    q.push(3);

    // Dequeue elements and print
    while (!q.empty()) {
        cout << q.front() << " "; // Print the front element
        q.pop(); // Remove the front element
    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    vector<int> data;

public:
    // Function to push an item onto the stack
    void push(int item) {
        data.push_back(item);
        cout << "Pushed " << item << " onto the stack." << endl;
    }

    // Function to pop an item from the stack
    int pop() {
        if (data.empty()) {
            cout << "Stack is empty, cannot pop." << endl;
            return -1; // Return a default value indicating failure
        } else {
            int popped_item = data.back();
            data.pop_back();
            cout << "Popped " << popped_item << " from the stack." << endl;
            return popped_item;
        }
    }
};

int main() {
    // Create a stack object
    Stack stack;

    // Example usage
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();
    stack.pop();

    return 0;
}

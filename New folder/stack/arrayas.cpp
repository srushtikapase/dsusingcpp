#include <iostream>
#include <cassert>

using namespace std;

const int MAX_SIZE = 100;

class ArrayStack {
    int arr[MAX_SIZE];
    int top;

public:
    ArrayStack() {
        top = -1;
    }

    void push(int value) {
        assert(top < MAX_SIZE - 1 && "Stack Overflow");
        arr[++top] = value;
    }

    void pop() {
        assert(top > -1 && "Stack Underflow");
        --top;
    }

    int peek() {
        assert(top > -1 && "Stack Underflow");
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    ArrayStack stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);

    cout << "Top element: " << stack.peek() << endl;
    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;

    return 0;
}

#include <iostream>
#include <cassert>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedListStack {
    Node* top;

public:
    LinkedListStack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        assert(top != nullptr && "Stack Underflow");
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        assert(top != nullptr && "Stack Underflow");
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    LinkedListStack stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);

    cout << "Top element: " << stack.peek() << endl;
    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;

    return 0;
}

#include <iostream>

struct Node {
    int data;
    Node* next;
};

class CircularSinglyLinkedList {
private:
    Node* tail;

public:
    CircularSinglyLinkedList() : tail(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!tail) {
            tail = newNode;
            tail->next = tail; // Point to itself
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    void display() {
        if (!tail) return;
        Node* temp = tail->next;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        std::cout << std::endl;
    }
};

int main() {
    CircularSinglyLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();
    return 0;
}

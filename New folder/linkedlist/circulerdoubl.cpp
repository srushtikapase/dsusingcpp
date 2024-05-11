#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class CircularDoublyLinkedList {
private:
    Node* tail;

public:
    CircularDoublyLinkedList() : tail(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!tail) {
            tail = newNode;
            tail->next = tail;
            tail->prev = tail;
            return;
        }
        newNode->next = tail->next;
        newNode->prev = tail;
        tail->next->prev = newNode;
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
    CircularDoublyLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();
    return 0;
}

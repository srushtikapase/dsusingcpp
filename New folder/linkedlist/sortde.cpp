#include <iostream>

struct Node {
    int data;
    Node* next;
};

class SortedLinkedList {
private:
    Node* head;

public:
    SortedLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head || head->data >= value) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->data < value) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    SortedLinkedList list;
    list.insert(30);
    list.insert(10);
    list.insert(20);
    list.display();
    return 0;
}

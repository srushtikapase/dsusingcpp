#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class SelfOrganizingList {
    Node* head;

public:
    SelfOrganizingList();
    ~SelfOrganizingList();
    void insert(int);
    void remove(int);
    bool search(int);
    void display();
};

SelfOrganizingList::SelfOrganizingList() {
    head = nullptr;
}

SelfOrganizingList::~SelfOrganizingList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void SelfOrganizingList::insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void SelfOrganizingList::remove(int value) {
    if (head == nullptr) return;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

bool SelfOrganizingList::search(int value) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (prev != nullptr) {
            prev->next = current->next;
            current->next = head;
            head = current;
        }
        return true;
    }

    return false;
}

void SelfOrganizingList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    SelfOrganizingList list;
    list.insert(3);
    list.insert(6);
    list.insert(7);
    list.insert(9);
    list.insert(12);
    list.insert(19);
    list.insert(17);
    list.insert(26);
    list.insert(21);
    list.insert(25);
    list.display();

    list.search(19);
    list.display();

    list.search(12);
    list.display();

    return 0;
}

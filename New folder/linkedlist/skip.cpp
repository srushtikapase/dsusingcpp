#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_LEVEL = 5;

// Node structure for Skip List
struct Node {
    int value;
    Node* forward[MAX_LEVEL + 1];
};

class SkipList {
    Node* header;
    int level;

public:
    SkipList();
    bool search(int);
    void insert(int);
    void remove(int);
    void display();
};

SkipList::SkipList() {
    header = new Node();
    level = 0;
    for (int i = 0; i <= MAX_LEVEL; i++)
        header->forward[i] = nullptr;
}

bool SkipList::search(int key) {
    Node* current = header;
    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->value < key)
            current = current->forward[i];
    }
    current = current->forward[0];
    return current != nullptr && current->value == key;
}

void SkipList::insert(int key) {
    Node* update[MAX_LEVEL + 1];
    Node* current = header;

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->value < key)
            current = current->forward[i];
        update[i] = current;
    }

    current = current->forward[0];
    if (current == nullptr || current->value != key) {
        int newLevel = 0;
        while (rand() % 2 && newLevel < MAX_LEVEL)
            newLevel++;
        
        if (newLevel > level) {
            for (int i = level + 1; i <= newLevel; i++)
                update[i] = header;
            level = newLevel;
        }

        Node* newNode = new Node();
        newNode->value = key;
        for (int i = 0; i <= newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

void SkipList::remove(int key) {
    Node* update[MAX_LEVEL + 1];
    Node* current = header;

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->value < key)
            current = current->forward[i];
        update[i] = current;
    }

    current = current->forward[0];
    if (current != nullptr && current->value == key) {
        for (int i = 0; i <= level; i++) {
            if (update[i]->forward[i] != current)
                break;
            update[i]->forward[i] = current->forward[i];
        }
        delete current;

        while (level > 0 && header->forward[level] == nullptr)
            level--;
    }
}

void SkipList::display() {
    cout << "Skip List:\n";
    for (int i = 0; i <= level; i++) {
        Node* node = header->forward[i];
        cout << "Level " << i << ": ";
        while (node != nullptr) {
            cout << node->value << " ";
            node = node->forward[i];
        }
        cout << endl;
    }
}

int main() {
    SkipList list;
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

    list.remove(12);
    list.remove(17);
    list.display();

    cout << "Search for 19: " << (list.search(19) ? "Found" : "Not found") << endl;
    cout << "Search for 12: " << (list.search(12) ? "Found" : "Not found") << endl;

    return 0;
}

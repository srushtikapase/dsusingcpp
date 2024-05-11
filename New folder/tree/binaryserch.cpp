#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

public:
    BST() {
        root = nullptr;
    }

    // Function to insert a value into the BST
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            node = new Node(value);
        } else if (value <= node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Function to insert a value into the BST
    void insert(int value) {
        root = insert(root, value);
    }
};

int main() {
    // Creating a sample BST
    BST bst;
    bst.insert(4);
    bst.insert(2);
    bst.insert(6);
    bst.insert(1);
    bst.insert(3);
    bst.insert(5);
    bst.insert(7);

    // Example usage
    cout << "Binary Search Tree (BST):" << endl;
    cout << "    4" << endl;
    cout << "   / \\" << endl;
    cout << "  2   6" << endl;
    cout << " / \\ / \\" << endl;
    cout << "1  3 5  7" << endl;

    return 0;
}

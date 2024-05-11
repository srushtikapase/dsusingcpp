#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = right = nullptr;
        height = 1;
    }
};

// Function to get the height of a node
int height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Function to get the balance factor of a node
int balanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to update the height of a node
void updateHeight(Node* node) {
    node->height = 1 + max(height(node->left), height(node->right));
}

// Function to perform a right rotation
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    // Perform rotation
    x->right = y;
    y->left = T;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    // Return new root
    return x;
}

// Function to perform a left rotation
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    // Perform rotation
    y->left = x;
    x->right = T;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    // Return new root
    return y;
}

// Function to insert a value into the AVL tree
Node* insert(Node* node, int value) {
    if (node == nullptr)
        return new Node(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else // Duplicate values not allowed
        return node;

    // Update height of this ancestor node
    updateHeight(node);

    // Get the balance factor to check if this node became unbalanced
    int balance = balanceFactor(node);

    // Left Left Case
    if (balance > 1 && value < node->left->data)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && value > node->right->data)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && value > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    // If the node is balanced
    return node;
}

// Function to insert a value into the AVL tree
Node* insert(int value, Node* root) {
    return insert(root, value);
}

int main() {
    Node* root = nullptr;

    // Inserting elements into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Example usage
    cout << "AVL Tree:" << endl;
    cout << "     30" << endl;
    cout << "    /  \\" << endl;
    cout << "   20   40" << endl;
    cout << "  /  \\    \\" << endl;
    cout << " 10  25   50" << endl;

    return 0;
}

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

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Example usage
    cout << "Binary Tree:" << endl;
    cout << "     1" << endl;
    cout << "    / \\" << endl;
    cout << "   2   3" << endl;
    cout << "  / \\" << endl;
    cout << " 4   5" << endl;

    return 0;
}

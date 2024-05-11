#include <iostream>
#include <vector>

using namespace std;

// B-tree node
class BTreeNode {
    vector<int> keys;
    int t;  // Minimum degree
    vector<BTreeNode*> children;
    bool leaf;

public:
    BTreeNode(int _t, bool _leaf);
    void traverse();

    BTreeNode* search(int k);

    void insertNonFull(int k);

    void splitChild(int i, BTreeNode* y);
};

// Constructor for BTreeNode
BTreeNode::BTreeNode(int _t, bool _leaf) {
    t = _t;
    leaf = _leaf;

    // Allocate memory for maximum number of possible keys and children
    keys.resize(2 * t - 1);
    children.resize(2 * t);
}

// Traverse all nodes in a subtree rooted with this node
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < keys.size(); i++) {
        if (!leaf)
            children[i]->traverse();
        cout << " " << keys[i];
    }

    // Print the subtree rooted with the last child
    if (!leaf)
        children[i]->traverse();
}

// Search key k in subtree rooted with this node
BTreeNode* BTreeNode::search(int k) {
    int i = 0;
    while (i < keys.size() && k > keys[i])
        i++;

    if (keys[i] == k)
        return this;

    if (leaf)
        return nullptr;

    return children[i]->search(k);
}

// Insert a new key in this node
void BTreeNode::insertNonFull(int k) {
    int i = keys.size() - 1;

    if (leaf) {
        while (i >= 0 && k < keys[i]) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
    } else {
        while (i >= 0 && k < keys[i])
            i--;

        if (children[i + 1]->keys.size() == 2 * t - 1) {
            splitChild(i + 1, children[i + 1]);
            if (k > keys[i + 1])
                i++;
        }
        children[i + 1]->insertNonFull(k);
    }
}

// Split the child y of this node
void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->t, y->leaf);
    z->keys.resize(t - 1);

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (!y->leaf) {
        for (int j = 0; j < t; j++)
            z->children[j] = y->children[j + t];
    }

    y->keys.resize(t - 1);

    children.insert(children.begin() + i + 1, z);
    keys.insert(keys.begin() + i, y->keys[t - 1]);
}

// B-tree class
class BTree {
    BTreeNode* root;
    int t;

public:
    BTree(int _t) {
        root = nullptr;
        t = _t;
    }

    // Function to traverse the tree
    void traverse() {
        if (root != nullptr)
            root->traverse();
    }

    // Function to search given key in the tree
    BTreeNode* search(int k) {
        return (root == nullptr) ? nullptr : root->search(k);
    }

    // Function to insert a key into the tree
    void insert(int k) {
        if (root == nullptr) {
            root = new BTreeNode(t, true);
            root->keys.push_back(k);
        } else {
            if (root->keys.size() == 2 * t - 1) {
                BTreeNode* s = new BTreeNode(t, false);
                s->children.push_back(root);
                s->splitChild(0, root);

                int i = 0;
                if (s->keys[0] < k)
                    i++;
                s->children[i]->insertNonFull(k);

                root = s;
            } else {
                root->insertNonFull(k);
            }
        }
    }
};

// Main function
int main() {
    BTree bt(3); // B-tree with minimum degree 3

    bt.insert(10);
    bt.insert(20);
    bt.insert(5);
    bt.insert(6);
    bt.insert(12);
    bt.insert(30);
    bt.insert(7);
    bt.insert(17);

    cout << "Traversal of the constructed B-tree: ";
    bt.traverse();
    cout << endl;

    int key = 6;
    (bt.search(key) != nullptr) ? cout << "Key " << key << " found in the tree\n" : cout << "Key " << key << " not found in the tree\n";

    key = 15;
    (bt.search(key) != nullptr) ? cout << "Key " << key << " found in the tree\n" : cout << "Key " << key << " not found in the tree\n";

    return 0;
}

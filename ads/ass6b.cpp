#include <iostream>
#include <string>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    string data;
    Node* parent;
    Node* left;
    Node* right;
    Color color;

    Node(string val) : data(val), parent(nullptr), left(nullptr), right(nullptr), color(RED) {}
};

class RBTree {
private:
    Node* root;

    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
            y->left->parent = x;
        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nullptr)
            y->right->parent = x;
        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;

        y->right = x;
        x->parent = y;
    }

    void fixInsert(Node* node) {
        Node* parent = nullptr;
        Node* grandparent = nullptr;

        while (node != root && node->color == RED && node->parent->color == RED) {
            parent = node->parent;
            grandparent = parent->parent;

            if (parent == grandparent->left) {
                Node* uncle = grandparent->right;

                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                } else {
                    if (node == parent->right) {
                        rotateLeft(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    rotateRight(grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            } else {
                Node* uncle = grandparent->left;

                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                } else {
                    if (node == parent->left) {
                        rotateRight(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    rotateLeft(grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            }
        }
        root->color = BLACK;
    }

    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

public:
    RBTree() : root(nullptr) {}

    void insert(string val) {
        Node* newNode = new Node(val);

        if (root == nullptr) {
            root = newNode;
            root->color = BLACK;
            return;
        }

        Node* curr = root;
        Node* parent = nullptr;

        while (curr != nullptr) {
            parent = curr;
            if (val < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }

        newNode->parent = parent;
        if (val < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        fixInsert(newNode);
    }

    void display() {
        cout << "Tree (In-order): ";
        inOrder(root);
        cout << endl;
    }
};

int main() {
    RBTree tree;
    int choice;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Insert\n";
        cout << "2. Display Tree\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string val;
                cout << "Enter value: ";
                cin >> val;
                tree.insert(val);
                break;
            }
            case 2:
                tree.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while (choice != 0);

    return 0;
}

#include <iostream>
#include <queue>

using namespace std;

class BTreeNode {
public:
    int keys[3];  // Maximum keys for order 3
    BTreeNode* children[4]; // Max children = Order
    int numKeys;
    bool isLeaf;

    BTreeNode(bool leaf) {
        isLeaf = leaf;
        numKeys = 0;
        for (int i = 0; i < 4; i++) children[i] = nullptr;
    }
};

class BTree {
public:
    BTreeNode* root;

    BTree() { root = new BTreeNode(true); }

    void insert(int key) {
        BTreeNode* r = root;
        if (r->numKeys == 2) {
            BTreeNode* s = new BTreeNode(false);
            root = s;
            s->children[0] = r;
            splitChild(s, 0, r);
            insertNonFull(s, key);
        } else {
            insertNonFull(r, key);
        }
    }

    void levelOrderDisplay() {
        if (!root) return;

        queue<BTreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            BTreeNode* node = q.front();
            q.pop();

            for (int i = 0; i < node->numKeys; i++)
                cout << node->keys[i] << " ";
            cout << " | ";

            if (!node->isLeaf) {
                for (int i = 0; i <= node->numKeys; i++)
                    q.push(node->children[i]);
            }
        }
        cout << endl;
    }

    void remove(int key) {
        root = deleteKey(root, key);
    }

private:
    void insertNonFull(BTreeNode* node, int key) {
        int i = node->numKeys - 1;
        if (node->isLeaf) {
            while (i >= 0 && key < node->keys[i]) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
            node->numKeys++;
        } else {
            while (i >= 0 && key < node->keys[i]) i--;
            i++;
            if (node->children[i]->numKeys == 2) {
                splitChild(node, i, node->children[i]);
                if (key > node->keys[i]) i++;
            }
            insertNonFull(node->children[i], key);
        }
    }

    void splitChild(BTreeNode* parent, int i, BTreeNode* child) {
        BTreeNode* newNode = new BTreeNode(child->isLeaf);
        newNode->keys[0] = child->keys[2];

        if (!child->isLeaf) {
            newNode->children[0] = child->children[2];
            newNode->children[1] = child->children[3];
        }

        child->numKeys = 1;
        for (int j = parent->numKeys; j > i; j--) {
            parent->children[j + 1] = parent->children[j];
            parent->keys[j] = parent->keys[j - 1];
        }
        parent->keys[i] = child->keys[1];
        parent->children[i + 1] = newNode;
        parent->numKeys++;
    }

    BTreeNode* deleteKey(BTreeNode* node, int key) {
        if (!node) return node;

        int i;
        for (i = 0; i < node->numKeys && key > node->keys[i]; i++);

        if (i < node->numKeys && key == node->keys[i]) {
            if (node->isLeaf) {
                for (int j = i; j < node->numKeys - 1; j++)
                    node->keys[j] = node->keys[j + 1];
                node->numKeys--;
            }
            return node;
        }

        if (!node->isLeaf) {
            node->children[i] = deleteKey(node->children[i], key);
        }
        return node;
    }
};

void menu(BTree& tree) {
    int choice, key;
    while (true) {
        cout << "\nB-Tree Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Level Order Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                tree.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                tree.remove(key);
                break;
            case 3:
                cout << "B-Tree Level Order: ";
                tree.levelOrderDisplay();
                break;
            case 4:
                return;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

int main() {
    BTree tree;
    menu(tree);
    return 0;
}

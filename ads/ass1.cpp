#include <iostream> 
using namespace std;

class Node
{
public:
    string key;
    string value;
    Node *left, *right;

    Node(string k, string v)
    {
        key = k;
        value = v;
        left = nullptr;
        right = nullptr;
    }
};
class Stack
{
public:
    class StackNode
    {
    public:
        Node *data;
        StackNode *next;
        StackNode(Node *n)
        {
            data = n;
            next = nullptr;
        }
    };
    StackNode *top;

public:
    Stack()
    {
        top = nullptr;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    void push(Node *n)
    {
        StackNode *newNode = new StackNode(n);
        newNode->next = top;
        top = newNode;
    }

    Node *pop()
    {
        if (isEmpty())
        {
            return nullptr;
        }
        StackNode *temp = top;
        Node *data = top->data;
        top = top->next;
        delete temp;
        return data;
    }
    Node *peek()
    {
        if (isEmpty())
        {
            return nullptr;
        }
        return top->data;
    }
};

class Queue
{
public:
    class QueueNode
    {
    public:
        Node *data;
        QueueNode *next;
        QueueNode(Node *n)
        {
            data = n;
            next = nullptr;
        }
    };
    QueueNode *front, *rear;

public:
    Queue()
    {

        front = nullptr;
        rear = nullptr;
    }
    bool isEmpty()
    {
        return front == nullptr;
    }
    void enqueue(Node *n)
    {
        QueueNode *newNode = new QueueNode(n);
        if (rear != nullptr)
        {
            rear->next = newNode;
        }
        rear = newNode;
        if (front == nullptr)
        {
            front = rear;
        }
    }
    Node *dequeue()
    {
        if (isEmpty())
        {
            return nullptr;
        }
        QueueNode *temp = front;
        Node *data = front->data;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
        return data;
    }
};
class Dictionary
{

private:
    Node *root;
    Node *insert(Node *node, string key, string value)
    {
        if (node == nullptr)
        {
            return new Node(key, value);
        }
        if (key < node->key)
        {
            node->left = insert(node->left, key, value);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, key, value);
        }
        else
        {
            node->value = value; // Update value if key exists
        }
        return node;
    }
    Node *minValueNode(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }
    Node *deleteNode(Node *node, string key)
    {
        if (node == nullptr)
        {
            return node;
        }
        if (key < node->key)
        {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = deleteNode(node->right, key);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node *temp = node->right;

                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = minValueNode(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->key);
        }
        return node;
    }
    Node *search(Node *node, string key)
    {
        if (node == nullptr || node->key == key)
        {
            return node;
        }
        if (key < node->key)
        {
            return search(node->left, key);
        }
        return search(node->right, key);
    }
    void inorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorder(node->left);
        cout << node->key << " : " << node->value << endl;
        inorder(node->right);
    }
    void inorderIterative(Node *root)
    {

        Stack stack;
        Node *curr = root;
        while (curr || !stack.isEmpty())
        {
            if (curr)
            {
                stack.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = stack.pop();
                cout << curr->key << " : " << curr->value << endl;
                curr = curr->right;
            }
        }
    }
    Node *mirror(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        Node *mirrored = new Node(node->key, node->value);
        mirrored->left = mirror(node->right);
        mirrored->right = mirror(node->left);
        return mirrored;
    }
    Node *copyTree(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        Node *newNode = new Node(node->key, node->value);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);
        return newNode;
    }
    void levelOrder(Node *node)
    {

        if (node == nullptr)
        {
            return;
        }
        Queue q;
        q.enqueue(node);
        while (!q.isEmpty())
        {
            Node *temp = q.dequeue();
            cout << temp->key << " : " << temp->value << " | ";
            if (temp->left != nullptr)
            {
                q.enqueue(temp->left);
            }
            if (temp->right != nullptr)
            {
                q.enqueue(temp->right);
            }
        }
        cout << endl;
    }

public:
    Dictionary()
    {
        root = nullptr;
    }
    void insert(string key, string value)
    {
        root = insert(root, key, value);
    }
    void remove(string key)
    {
        root = deleteNode(root, key);
    }
    void search(string key)
    {
        Node *res = search(root, key);
        if (res != nullptr)
        {
            cout << "Found: " << res->key << " -> " << res->value << endl;
        }
        else
        {
            cout << "Not Found" << endl;
        }
    }
    void display()
    {
        // inorder(root); inorderIterative(root);
    }
    void displayMirror()
    {
        Node *mirrored = mirror(root);
        inorder(mirrored);
    }
    void copyDictionary()
    {
        Node *copied = copyTree(root);
        inorder(copied);
    }
    void displayLevelWise()
    {
        levelOrder(root);
    }
};
int main()
{
    Dictionary dict;
    int choice;
    string word, meaning;
    do
    {
        cout << "\n===== Dictionary Menu =====\n";
        cout << "1. Insert a word\n";
        cout << "2. Search for a word\n";
        cout << "3. Delete a word\n";

        cout << "4. Display dictionary (Sorted Order)\n";
        cout << "5. Display dictionary (Level Order)\n";
        cout << "6. Display Mirror Image\n";
        cout << "7. Create a Copy of Dictionary\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter word: ";
            cin >> word;
            cout << "Enter meaning: ";
            cin.ignore();
            getline(cin, meaning);
            dict.insert(word, meaning);
            cout << "Word added successfully!\n";
            break;
        case 2:
            cout << "Enter word to search: ";
            cin >> word;
            dict.search(word);
            break;
        case 3:
            cout << "Enter word to delete: ";
            cin >> word;
            dict.remove(word);
            cout << "Word deleted successfully!\n";
            break;
        case 4:
            cout << "\nDictionary (Sorted Order):\n";
            dict.display();

            break;
        case 5:
            cout << "\nDictionary (Level Order):\n";
            dict.displayLevelWise();
            break;
        case 6:
            cout << "\nMirror Image of Dictionary:\n";
            dict.displayMirror();
            break;
        case 7:
            cout << "\nCreating a Copy of Dictionary...\n";
            dict.copyDictionary();
            break;
        case 8:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);
    return 0;
}

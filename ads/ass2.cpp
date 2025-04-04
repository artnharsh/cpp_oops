#include<iostream>
using namespace std;

class node{
    public:
        int score;
        string player_name;
        string player_id;
        node* left;
        node* right;
        node(int score, string name, string id){
            this->score = score;
            this->player_name = name;
            this->player_id = id;
            this->left = nullptr;
            this->right = nullptr;
        }
};

class AVLtree{
    public:
    node* root;
    AVLtree(){
        root = nullptr;
    }

    node* insert(node* p, int score, string name, string id){
        if(p == NULL){
            return new node(score, name, id);
        }
        if(score < p -> score){
            p -> left = insert(p -> left, score, name, id);
        }else if(score > p -> score){
            p -> right = insert(p -> right, score, name, id);
        }
        return balanced(p);
    }

    node* balanced(node* p){
        int balance_factor = get_balance_factor(p);
        
        if(balance_factor > 1){
            if(p -> left -> score > p -> left -> left -> score){
                return right_rotate(p);
            }
            p -> left = left_rotate(p -> left);
            return right_rotate(p);
        }

        if(balance_factor < -1){
            if(p -> right -> score < p -> right -> right -> score){
                return left_rotate(p);
            }
            p -> right = right_rotate(p -> right);
            return left_rotate(p);
        }
        return p;
    }

    int get_balance_factor(node* p){
        if(p == nullptr) return 0;
        return height(p -> left) - height(p -> right);
    }

    int height(node* p){
        if(p == nullptr) return 0;
        return max(height(p -> left), height(p -> right)) + 1;
    }

    node* right_rotate(node* z){
        node* y = z -> left;
        node* T3 = y -> right;
        y -> right = z;
        z -> left = T3;
        return y;
    }

    node* left_rotate(node* y){
        node* x = y -> right;
        node* T2 = x -> left;
        x -> left = y;
        y -> right = T2;
        return x;
    }

    node* Delete(node* p, int score){
        if(p == nullptr) return p;

        // Searching for the node to be deleted
        if(score < p -> score){
            p -> left = Delete(p -> left, score);
        } else if(score > p -> score){
            p -> right = Delete(p -> right, score);
        } else{
            // Node with only one child or no child
            if(p -> left == nullptr || p -> right == nullptr){
                node* temp = p -> left ? p -> left : p -> right;
                if(temp == nullptr){
                    temp = p;
                    p = nullptr;
                } else{
                    *p = *temp;
                }
                delete temp;
            } else{
                // Node with two children
                node* temp = min_value_node(p -> right);
                p -> score = temp -> score;
                p -> player_name = temp -> player_name;
                p -> player_id = temp -> player_id;
                p -> right = Delete(p -> right, temp -> score); // Recur for the right subtree
            }
        }
        if(p == nullptr) return p;
        return balanced(p); // Return the balanced node
    }

    node* min_value_node(node* p){
        node* current = p;
        while(current -> left != nullptr){
            current = current -> left;
        }
        return current;
    }

    // Function to print the tree in an inorder manner for testing
    void inorder(node* p) {
        if (p == nullptr) return;
        inorder(p -> left);
        cout << p -> score << " " << p -> player_name << " " << p -> player_id << endl;
        inorder(p -> right);
    }

    void print_tree(){
        inorder(root);
    }
};

int main() {
    AVLtree tree;
    int choice, score;
    string name, id;
    bool flag = 0;

    while (true) {
        cout << "\n------ Menu ------" << endl;
        cout << "1. Insert Player" << endl;
        cout << "2. Delete Player" << endl;
        cout << "3. Display Tree (Inorder Traversal)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Player Score: ";
                cin >> score;
                cout << "Enter Player Name: ";
                cin >> name;
                cout << "Enter Player ID: ";
                cin >> id;
                
                tree.root = tree.insert(tree.root, score, name, id);
                cout << "Player inserted successfully!" << endl;
                flag = 1;
                break;


            case 2:
                cout << "Enter Player Score to delete: ";
                cin >> score;
                tree.root = tree.Delete(tree.root, score);
                cout << "Player deleted successfully!" << endl;
                break;

            case 3:
                cout << "AVL Tree Inorder Traversal:" << endl;
                tree.print_tree();
                break;

            case 4:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}

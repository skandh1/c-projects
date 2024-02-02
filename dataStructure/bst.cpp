#include <iostream>
#include <stack>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;
        while (true) {
            if (value < current->data) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    return;
                }
                current = current->left;
            } else if (value > current->data) {
                if (current->right == nullptr) {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            } else {
                // Value already exists in the tree
                delete newNode;
                return;
            }
        }
    }

    bool search(int value) {
        Node* current = root;

        while (current != nullptr) {
            if (value == current->data) {
                return true;
            } else if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        return false;
    }

    void displayTree(Node* node, int level) {
        if (node != nullptr) {
            displayTree(node->right, level + 1);
            for (int i = 0; i < level; ++i) {
                std::cout << "    ";
            }
            std::cout << node->data << std::endl;
            displayTree(node->left, level + 1);
        }
    }

    void display() {
        displayTree(root, 0);
    }
};

int main() {
    BinaryTree tree;
    int value;

    do {
        std::cout << "Enter a value to insert into the tree (0 to exit): ";
        std::cin >> value;

        if (value != 0) {
            tree.insert(value);
            std::cout << "Tree after insertion:" << std::endl;
            tree.display();
        }

    } while (value != 0);

    return 0;
}

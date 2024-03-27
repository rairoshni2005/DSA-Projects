#include <iostream>
using namespace std;

// Define the structure for a node in the binary search tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a node with data and null left and right pointers
    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    TreeNode* root;

    // Function to recursively insert a node into the binary search tree
    TreeNode* insertRec(TreeNode* root, int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        } else if (value <= root->data) {
            root->left = insertRec(root->left, value);
        } else {
            root->right = insertRec(root->right, value);
        }
        return root;
    }

    // Function to recursively search for a value in the binary search tree
    bool searchRec(TreeNode* root, int value) {
        if (root == nullptr) {
            return false;
        } else if (root->data == value) {
            return true;
        } else if (value < root->data) {
            return searchRec(root->left, value);
        } else {
            return searchRec(root->right, value);
        }
    }

    // Function to recursively traverse the binary search tree in inorder fashion
    void inorderRec(TreeNode* root) {
        if (root != nullptr) {
            inorderRec(root->left);
            cout << root->data << " ";
            inorderRec(root->right);
        }
    }

public:
    // Constructor to initialize an empty binary search tree
    BinarySearchTree() {
        root = nullptr;
    }

    // Function to insert a value into the binary search tree
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Function to search for a value in the binary search tree
    bool search(int value) {
        return searchRec(root, value);
    }

    // Function to traverse the binary search tree in inorder fashion
    void inorderTraversal() {
        inorderRec(root);
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    cout << "Inorder traversal of the binary search tree: ";
    bst.inorderTraversal();  // Output: Inorder traversal of the binary search tree: 1 3 4 5 6 7 8
    cout << endl;

    cout << "Search for value 4: " << (bst.search(4) ? "Found" : "Not found") << endl;  // Output: Search for value 4: Found
    cout << "Search for value 9: " << (bst.search(9) ? "Found" : "Not found") << endl;  // Output: Search for value 9: Not found

    return 0;
}

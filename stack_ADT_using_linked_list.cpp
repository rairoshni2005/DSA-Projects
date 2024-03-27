#include <iostream>
using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;

    // Constructor to initialize a node with data and next pointer
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class StackLinkedList {
private:
    Node* top;
    int size;

public:
    // Constructor to initialize an empty stack
    StackLinkedList() {
        top = nullptr;
        size = 0;
    }

    // Destructor to free the memory allocated for nodes
    ~StackLinkedList() {
        Node* current = top;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        top = nullptr;
    }

    // Function to push a new element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Function to pop the top element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop from an empty stack." << endl;
            return -1;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return poppedValue;
    }

    // Function to peek at the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek into an empty stack." << endl;
            return -1;
        }
        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to get the size of the stack
    int getSize() {
        return size;
    }
};

int main() {
    StackLinkedList stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element of the stack: " << stack.peek() << endl;  // Output: Top element of the stack: 3

    cout << "Popped element: " << stack.pop() << endl;  // Output: Popped element: 3

    cout << "Top element of the stack after popping: " << stack.peek() << endl;  // Output: Top element of the stack after popping: 2

    return 0;
}

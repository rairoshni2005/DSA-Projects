#include <iostream>
#include <stdexcept>

using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

class Stack {
private:
    int arr[MAX_SIZE];
    int top; // Index of the top element

public:
    Stack() {
        top = -1; // Stack is initially empty
    }

    // Function to push an element onto the stack
    void push(int val) {
        if (top == MAX_SIZE - 1) {
            throw overflow_error("Stack overflow"); // Cannot push more elements, stack is full
        }
        arr[++top] = val; // Increment top and insert the element
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            throw underflow_error("Stack underflow"); // Cannot pop, stack is empty
        }
        return arr[top--]; // Decrement top and return the element
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to get the element at the top of the stack without removing it
    int peek() {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return arr[top];
    }
};

int main() {
    Stack stack;

    // Pushing elements onto the stack
    stack.push(5);
    stack.push(10);
    stack.push(15);

    // Peeking at the top element
    cout << "Top element: " << stack.peek() << endl;

    // Popping elements from the stack
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    // Checking if the stack is empty
    cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

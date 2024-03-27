#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *queue;
    int capacity;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int cap) {
        capacity = cap;
        queue = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue more items." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        queue[rear] = item;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue from an empty queue." << endl;
            return -1;
        }
        int item = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return item;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek into an empty queue." << endl;
            return -1;
        }
        return queue[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue contents: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.display();  // Output: Queue contents: 1 2 3 4 5

    cout << "Dequeue: " << queue.dequeue() << endl;  // Output: Dequeue: 1

    queue.display();  // Output: Queue contents: 2 3 4 5

    cout << "Peek: " << queue.peek() << endl;  // Output: Peek: 2

    queue.enqueue(6);
    queue.enqueue(7);

    queue.display();  // Output: Queue contents: 2 3 4 5 6 7

    return 0;
}

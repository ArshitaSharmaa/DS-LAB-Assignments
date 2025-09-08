#include <iostream>
using namespace std;
const int SIZE = 100;
int q[SIZE];
int front = -1, rear = -1;
bool isEmpty() { return front == -1; }
void enqueue(int x) {
    if (rear == SIZE - 1) return;
    if (front == -1) front = 0;
    q[++rear] = x;
}
int dequeue() {
    if (isEmpty()) return -1;
    int x = q[front++];
    if (front > rear) front = rear = -1;
    return x;
}
void push(int x) {
    enqueue(x);
    // rotate elements except new one
    for (int i = 0; i < rear - front; i++) {
        enqueue(dequeue());
    }
}
void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << "Popped: " << dequeue() << endl;
}
void display() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = front; i <= rear; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
}
int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}

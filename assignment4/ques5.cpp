#include <iostream>
using namespace std;
const int SIZE = 100;
// queue variables
int q1[SIZE], q2[SIZE];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;
bool isEmpty1() { return front1 == -1; }
bool isEmpty2() { return front2 == -1; }
void enqueue1(int x) {
    if (rear1 == SIZE - 1) return;
    if (front1 == -1) front1 = 0;
    q1[++rear1] = x;
}
int dequeue1() {
    if (isEmpty1()) return -1;
    int x = q1[front1++];
    if (front1 > rear1) front1 = rear1 = -1;
    return x;
}
void enqueue2(int x) {
    if (rear2 == SIZE - 1) return;
    if (front2 == -1) front2 = 0;
    q2[++rear2] = x;
}
int dequeue2() {
    if (isEmpty2()) return -1;
    int x = q2[front2++];
    if (front2 > rear2) front2 = rear2 = -1;
    return x;
}
void push(int x) {
    enqueue2(x); // step 1
    while (!isEmpty1()) {
        enqueue2(dequeue1()); // step 2
    }
    // swap q1 and q2
    swap(q1, q2);
    swap(front1, front2);
    swap(rear1, rear2);
}
void pop() {
    if (isEmpty1()) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << "Popped: " << dequeue1() << endl;
}
void display() {
    if (isEmpty1()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = front1; i <= rear1; i++) {
        cout << q1[i] << " ";
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

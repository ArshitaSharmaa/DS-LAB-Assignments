
#include <iostream>
using namespace std;
int main() {
    const int SIZE = 5;
    int queue[SIZE];
    int front = -1, rear = -1;
    int choice, value;
 do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
 switch(choice) {
case 1: // Enqueue
                if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
                    cout << "Queue is Full! Cannot enqueue.\n";
                } else {
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    if (front == -1) { // First element
                        front = rear = 0;
                    } else if (rear == SIZE - 1 && front != 0) {
                        rear = 0; // Wrap around
                    } else {
                        rear++;
                    }
                    queue[rear] = value;
                    cout << value << " enqueued.\n";
                }
                break;
 case 2: // Dequeue
                if (front == -1) {
                    cout << "Queue is Empty! Cannot dequeue.\n";
                } else {
                    cout << queue[front] << " dequeued.\n";
                    if (front == rear) { // Only one element
                        front = rear = -1;
                    } else if (front == SIZE - 1) {
                        front = 0; // Wrap around
                    } else {
                        front++;
                    }
                }
                break;
 case 3: // Peek
                if (front == -1) {
                    cout << "Queue is Empty.\n";
                } else {
                    cout << "Front element: " << queue[front] << endl;
                }
                break;
 case 4: // Display
                if (front == -1) {
                    cout << "Queue is Empty.\n";
                } else {
                    cout << "Queue elements: ";
                    if (rear >= front) {
                        for (int i = front; i <= rear; i++)
                            cout << queue[i] << " ";
                    } else {
                        for (int i = front; i < SIZE; i++)
                            cout << queue[i] << " ";
                        for (int i = 0; i <= rear; i++)
                            cout << queue[i] << " ";
                    }
                    cout << endl;
                }
                break;
 case 5: // isEmpty
                if (front == -1)
                    cout << "Queue is Empty.\n";
                else
                    cout << "Queue is NOT Empty.\n";
                break;
 case 6: // isFull
                if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
                    cout << "Queue is Full.\n";
                else
                    cout << "Queue is NOT Full.\n";
                break;
 case 7: // Exit
                cout << "Exiting program...\n";
                break;
default:
                cout << "Invalid choice! Try again.\n";
        }
} while(choice != 7);
return 0;
}

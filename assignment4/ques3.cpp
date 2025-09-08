#include <iostream>
using namespace std;
int main() {
    const int SIZE = 100;
    int queue[SIZE];
    int n;
cout << "Enter number of elements (even number): ";
    cin >> n;
cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> queue[i];
    }
int half = n / 2;
    int result[SIZE];
    int idx = 0;
for (int i = 0; i < half; i++) {
        result[idx++] = queue[i];        // take from first half
        result[idx++] = queue[i + half]; // take from second half
    }
cout << "Interleaved Queue: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
 return 0;
}

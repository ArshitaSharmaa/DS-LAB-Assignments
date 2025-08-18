#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;

    // Check distinct elements
    for (int i = 0; i < n; i++) {
        bool isDistinct = true;

        // check if arr[i] appeared before
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }

        if (isDistinct) count++;
    }

    cout << "Total number of distinct elements = " << count << endl;

    return 0;
}

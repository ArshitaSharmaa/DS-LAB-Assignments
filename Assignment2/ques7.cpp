#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int inversionCount = 0;

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                inversionCount++;
                cout << "(" << arr[i] << "," << arr[j] << ") "; 
            }
        }
    }

    cout << "Total number of inversions = " << inversionCount << endl;

    return 0;
}

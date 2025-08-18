#include <iostream>
using namespace std;

int main() {
    int termsA, termsB;
    cout << "Enter number of non-zero elements in Matrix A: ";
    cin >> termsA;
    
    int A[termsA][3]; // Triplet: row, col, value
    cout << "Enter row, column, value for Matrix A:\n";
    for (int i = 0; i < termsA; i++) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }

    cout << "Enter number of non-zero elements in Matrix B: ";
    cin >> termsB;

    int B[termsB][3]; // Triplet: row, col, value
    cout << "Enter row, column, value for Matrix B:\n";
    for (int i = 0; i < termsB; i++) {
        cin >> B[i][0] >> B[i][1] >> B[i][2];
    }

    // Result array (maximum size = sum of non-zero terms)
    int result[termsA + termsB][3];
    int i = 0, j = 0, k = 0;

    // Add matrices
    while (i < termsA && j < termsB) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            // A comes first
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2];
            i++; k++;
        } 
        else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            // B comes first
            result[k][0] = B[j][0];
            result[k][1] = B[j][1];
            result[k][2] = B[j][2];
            j++; k++;
        } 
        else {
            // Same row and col → add values
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
    }

    // Copy remaining elements
    while (i < termsA) {
        result[k][0] = A[i][0];
        result[k][1] = A[i][1];
        result[k][2] = A[i][2];
        i++; k++;
    }
    while (j < termsB) {
        result[k][0] = B[j][0];
        result[k][1] = B[j][1];
        result[k][2] = B[j][2];
        j++; k++;
    }

    // Print result
    cout << "\nResultant Sparse Matrix (Triplet Form):\n";
    cout << "Row Col Value\n";
    for (int x = 0; x < k; x++) {
        cout << result[x][0] << "   " << result[x][1] << "   " << result[x][2] << "\n";
    }

    return 0;
}

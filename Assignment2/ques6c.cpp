#include <iostream>
using namespace std;

int main() {
    int r1, c1, n1;
    cout << "Enter rows, cols and non-zero elements of first matrix: ";
    cin >> r1 >> c1 >> n1;

    int A[100][3];   // triplet form of A
    cout << "Enter row col value for A:\n";
    for (int i = 0; i < n1; i++) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }

    int r2, c2, n2;
    cout << "Enter rows, cols and non-zero elements of second matrix: ";
    cin >> r2 >> c2 >> n2;

    int B[100][3];   // triplet form of B
    cout << "Enter row col value for B:\n";
    for (int i = 0; i < n2; i++) {
        cin >> B[i][0] >> B[i][1] >> B[i][2];
    }

    if (c1 != r2) {
        cout << "Matrix multiplication not possible!";
        return 0;
    }

    // Temporary result stored as normal 2D array
    int C[50][50];
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
        }
    }

    // Multiply using sparse triplets
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (A[i][1] == B[j][0]) {  
                // column of A == row of B
                C[A[i][0]][B[j][1]] += A[i][2] * B[j][2];
            }
        }
    }

    // Convert result into triplet form
    int Res[100][3];
    int nz = 0;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            if (C[i][j] != 0) {
                Res[nz][0] = i;
                Res[nz][1] = j;
                Res[nz][2] = C[i][j];
                nz++;
            }
        }
    }

    cout << "\nResultant matrix in triplet form:\n";
    cout << "Row Col Val\n";
    for (int i = 0; i < nz; i++) {
        cout << Res[i][0] << " " << Res[i][1] << " " << Res[i][2] << "\n";
    }

    return 0;
}
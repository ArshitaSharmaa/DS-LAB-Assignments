#include <iostream>
using namespace std;

int main() {
    int rows, cols, terms;
    cout << "Enter rows, cols, non-zero terms: ";
    cin >> rows >> cols >> terms;

    // Triplet matrix representation
    int triplet[terms][3];
    cout << "Enter row col value for each non-zero element:\n";
    for (int i = 0; i < terms; i++) {
        cin >> triplet[i][0] >> triplet[i][1] >> triplet[i][2];
    }

    cout << "\nOriginal Triplet Matrix:\n";
    for (int i = 0; i < terms; i++) {
        cout << triplet[i][0] << " " << triplet[i][1] << " " << triplet[i][2] << endl;
    }

    // Transpose -> swap row and column
    int trans[terms][3];
    for (int i = 0; i < terms; i++) {
        trans[i][0] = triplet[i][1];
        trans[i][1] = triplet[i][0];
        trans[i][2] = triplet[i][2];
    }

    // Sort by row, then col (for proper order)
    for (int i = 0; i < terms - 1; i++) {
        for (int j = i + 1; j < terms; j++) {
            if (trans[i][0] > trans[j][0] || 
               (trans[i][0] == trans[j][0] && trans[i][1] > trans[j][1])) {
                swap(trans[i][0], trans[j][0]);
                swap(trans[i][1], trans[j][1]);
                swap(trans[i][2], trans[j][2]);
            }
        }
    }
    
    cout << "\nTranspose Triplet Matrix:\n";
    for (int i = 0; i < terms; i++) {
        cout << trans[i][0] << " " << trans[i][1] << " " << trans[i][2] << endl;
    }

    return 0;
}


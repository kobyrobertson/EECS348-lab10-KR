#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <utility>
using namespace std;

class Matrix {
private:
    int size;
    vector<vector<int>> data;

public:
    Matrix(int n) {
        size = n;
        data.resize(n, vector<int>(n, 0));
    }

    void readMatrix(istream& file) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> data[i][j];
            }
        }
    }

    void displayMatrix() const {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << setw(4) << data[i][j];
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(size);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(size);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    void diagonalSums() const {
        int mainSum = 0;
        int secondarySum = 0;

        for (int i = 0; i < size; i++) {
            mainSum += data[i][i];
            secondarySum += data[i][size - 1 - i];
        }

        cout << "Main diagonal sum: " << mainSum << endl;
        cout << "Secondary diagonal sum: " << secondarySum << endl;
    }

    void swapRows(int row1, int row2) {
        if (row1 >= 0 && row1 < size && row2 >= 0 && row2 < size) {
            swap(data[row1], data[row2]);
        }
    }

    void swapColumns(int col1, int col2) {
        if (col1 >= 0 && col1 < size && col2 >= 0 && col2 < size) {
            for (int i = 0; i < size; i++) {
                swap(data[i][col1], data[i][col2]);
            }
        }
    }

    void updateElement(int row, int col, int value) {
        if (row >= 0 && row < size && col >= 0 && col < size) {
            data[row][col] = value;
        }
    }
};

void swapMatrixRows(Matrix matrix, int row1 = 0, int row2 = 1) {
    matrix.swapRows(row1, row2);
    matrix.displayMatrix();
}

void swapMatrixColumns(Matrix matrix, int col1 = 0, int col2 = 1) {
    matrix.swapColumns(col1, col2);
    matrix.displayMatrix();
}

void updateMatrix(Matrix matrix, int row = 0, int col = 0, int value = 100) {
    matrix.updateElement(row, col, value);
    matrix.displayMatrix();
}

int main() {
    string filename;

    cout << "Enter input filename: ";
    getline(cin, filename);
    cout << endl;

    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int n;
    file >> n;

    Matrix A(n);
    Matrix B(n);

    A.readMatrix(file);
    B.readMatrix(file);

    cout << "Matrix A:" << endl;
    A.displayMatrix();
    cout << endl;

    cout << "Matrix B:" << endl;
    B.displayMatrix();
    cout << endl;

    cout << "A + B:" << endl;
    Matrix sum = A + B;
    sum.displayMatrix();
    cout << endl;

    cout << "A * B:" << endl;
    Matrix product = A * B;
    product.displayMatrix();
    cout << endl;

    cout << "Diagonal sums for Matrix A:" << endl;
    A.diagonalSums();
    cout << endl;

    cout << "Problem 5 - Rows 0 and 2 swapped:" << endl;
    swapMatrixRows(A, 0, 2);
    cout << endl;

    cout << "Problem 6 - Columns 0 and 2 swapped:" << endl;
    swapMatrixColumns(A, 0, 2);
    cout << endl;

    cout << "Problem 7 - Updated matrix:" << endl;
    updateMatrix(A, 1, 2, 99);

    return 0;
}
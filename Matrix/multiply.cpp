#include <bits/stdc++.h>

using namespace std;

typedef vector<int> Row;

class Matrix {
    vector<Row> matrix;
    int n;
public:
    Matrix(int n) {
        this->n = n;
        this->matrix = vector<Row>(n, Row(n));
    }

    Matrix operator+(const Matrix& B) {
        Matrix C(n);
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                C.matrix[i][j] = this->matrix[i][j] + B.matrix[i][j];
            }
        }
        return C;
    }

    Matrix operator-(const Matrix& B) {
        Matrix C(n);
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                C.matrix[i][j] = this->matrix[i][j] - B.matrix[i][j];
            }
        }
        return C;
    }

    bool operator==(const Matrix& B) const {
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( this->matrix[i][j] != B.matrix[i][j] ) {
                    return false;
                }
            }
        }
        return true;
    }

    Row& operator[](int i) {
        return matrix[i];
    }

    const Row& operator[](int i) const {
        return matrix[i];
    }

    int size() const noexcept {
        return n;
    }


};

Matrix recursiveMultiplySquareMatrix(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n);
    if ( n == 1 ) {
        C[0][0] = A[0][0] * B[0][0];
    }
    else {
        Matrix A11(n / 2), A12(n / 2), A21(n / 2), A22(n / 2);
        Matrix B11(n / 2), B12(n / 2), B21(n / 2), B22(n / 2);
        Matrix C11(n / 2), C12(n / 2), C21(n / 2), C22(n / 2);
        for ( int i = 0; i < n / 2; i++ ) {
            for ( int j = 0; j < n / 2; j++ ) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + n / 2];
                A21[i][j] = A[i + n / 2][j];
                A22[i][j] = A[i + n / 2][j + n / 2];
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + n / 2];
                B21[i][j] = B[i + n / 2][j];
                B22[i][j] = B[i + n / 2][j + n / 2];
            }
        }
        C11 = recursiveMultiplySquareMatrix(A11, B11) + recursiveMultiplySquareMatrix(A12, B21);
        C12 = recursiveMultiplySquareMatrix(A11, B12) + recursiveMultiplySquareMatrix(A12, B22);
        C21 = recursiveMultiplySquareMatrix(A21, B11) + recursiveMultiplySquareMatrix(A22, B21);
        C22 = recursiveMultiplySquareMatrix(A21, B12) + recursiveMultiplySquareMatrix(A22, B22);
        for ( int i = 0; i < n / 2; i++ ) {
            for ( int j = 0; j < n / 2; j++ ) {
                C[i][j] = C11[i][j];
                C[i][j + n / 2] = C12[i][j];
                C[i + n / 2][j] = C21[i][j];
                C[i + n / 2][j + n / 2] = C22[i][j];
            }
        }
    }
    return C;
}

Matrix iterativeMultiplicationSquareMatrix(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n);
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            C[i][j] = 0;
            for ( int k = 0; k < n; k++ ) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

Matrix generateRandomMatrix(int n) {
    Matrix A(n);
    int q = n * n;
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            A[i][j] = rand() % q;
        }
    }
    return A;
}

int main() {
    srand(time(0));
    int n = 1 << 5;
    Matrix A = generateRandomMatrix(n);
    Matrix B = generateRandomMatrix(n);
    Matrix C = recursiveMultiplySquareMatrix(A, B);
    Matrix D = iterativeMultiplicationSquareMatrix(A, B);
    assert(C == D);
    cout << "Correct answer\n";
    return 0;
}
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

Matrix strassenMult(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n);
    if ( n == 1 ) {
        C[0][0] = A[0][0] * B[0][0];
    }
    else {
        Matrix A11(n / 2), A12(n / 2), A21(n / 2), A22(n / 2);
        Matrix B11(n / 2), B12(n / 2), B21(n / 2), B22(n / 2);
        Matrix C11(n / 2), C12(n / 2), C21(n / 2), C22(n / 2);
        Matrix P1(n / 2), P2(n / 2), P3(n / 2), P4(n / 2), P5(n / 2), P6(n / 2), P7(n / 2);
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

        P1 = strassenMult(A11, B12 - B22);
        P2 = strassenMult(A11 + A12, B22);
        P3 = strassenMult(A21 + A22, B11);
        P4 = strassenMult(A22, B21 - B11);
        P5 = strassenMult(A11 + A22, B11 + B22);
        P6 = strassenMult(A12 - A22, B21 + B22);
        P7 = strassenMult(A11 - A21, B11 + B12);

        C11 = P5 + P4 - P2 + P6;
        C12 = P1 + P2;
        C21 = P3 + P4;
        C22 = P5 + P1 - P3 - P7;

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

int main() {
    Matrix A(4), B(4);
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3; A[0][3] = 4;
    A[1][0] = 5; A[1][1] = 6; A[1][2] = 7; A[1][3] = 8;
    A[2][0] = 9; A[2][1] = 10; A[2][2] = 11; A[2][3] = 12;
    A[3][0] = 13; A[3][1] = 14; A[3][2] = 15; A[3][3] = 16;

    B[0][0] = 16; B[0][1] = 15; B[0][2] = 14; B[0][3] = 13;
    B[1][0] = 12; B[1][1] = 11; B[1][2] = 10; B[1][3] = 9;
    B[2][0] = 8; B[2][1] = 7; B[2][2] = 6; B[2][3] = 5;
    B[3][0] = 4; B[3][1] = 3; B[3][2] = 2; B[3][3] = 1;

    Matrix C = strassenMult(A, B);
    for ( int i = 0; i < C.size(); i++ ) {
        for ( int j = 0; j < C.size(); j++ ) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}
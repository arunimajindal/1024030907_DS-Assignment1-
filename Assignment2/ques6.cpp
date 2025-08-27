#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

struct Term {
    int row, col, val;
};

vector<Term> readSparse(int rows, int cols, int nonZero) {
    vector<Term> mat;
    mat.push_back({rows, cols, nonZero}); 
    cout << "Enter non-zero elements as: row col value\n";
    for (int i = 0; i < nonZero; i++) {
        Term t;
        cin >> t.row >> t.col >> t.val;
        mat.push_back(t);
    }
    return mat;
}

void printSparse(const vector<Term>& mat) {
    cout << "Row  Col  Val\n";
    for (auto &t : mat) {
        cout << setw(3) << t.row << "  "
             << setw(3) << t.col << "  "
             << setw(3) << t.val << "\n";
    }
    cout << "------------------\n";
}

vector<Term> transposeSparse(const vector<Term>& mat) {
    int rows = mat[0].row, cols = mat[0].col, nonZero = mat[0].val;
    vector<Term> result;
    result.push_back({cols, rows, nonZero}); 

    for (int c = 0; c < cols; c++) {
        for (int i = 1; i <= nonZero; i++) {
            if (mat[i].col == c) {
                result.push_back({mat[i].col, mat[i].row, mat[i].val});
            }
        }
    }
    return result;
}

vector<Term> addSparse(const vector<Term>& A, const vector<Term>& B) {
    if (A[0].row != B[0].row || A[0].col != B[0].col) {
        cout << "Matrix dimensions mismatch! Cannot add.\n";
        return {};
    }

    vector<Term> result;
    result.push_back({A[0].row, A[0].col, 0}); 

    int i = 1, j = 1;
    while (i <= A[0].val && j <= B[0].val) {
        if (A[i].row == B[j].row && A[i].col == B[j].col) {
            int sumVal = A[i].val + B[j].val;
            if (sumVal != 0) result.push_back({A[i].row, A[i].col, sumVal});
            i++; j++;
        }
        else if ((A[i].row < B[j].row) ||
                 (A[i].row == B[j].row && A[i].col < B[j].col)) {
            result.push_back(A[i++]);
        } 
        else {
            result.push_back(B[j++]);
        }
    }
    while (i <= A[0].val) result.push_back(A[i++]);
    while (j <= B[0].val) result.push_back(B[j++]);

    result[0].val = result.size() - 1; 
    return result;
}

vector<Term> multiplySparse(const vector<Term>& A, const vector<Term>& B) {
    if (A[0].col != B[0].row) {
        cout << "Matrix dimensions mismatch! Cannot multiply.\n";
        return {};
    }

    vector<Term> result;
    result.push_back({A[0].row, B[0].col, 0}); 

    for (int i = 1; i <= A[0].val; i++) {
        for (int j = 1; j <= B[0].val; j++) {
            if (A[i].col == B[j].row) {
                int r = A[i].row;
                int c = B[j].col;
                int product = A[i].val * B[j].val;

                bool found = false;
                for (int k = 1; k < result.size(); k++) {
                    if (result[k].row == r && result[k].col == c) {
                        result[k].val += product;
                        found = true;
                        break;
                    }
                }
                if (!found && product != 0)
                    result.push_back({r, c, product});
            }
        }
    }

    result[0].val = result.size() - 1;
    return result;
}

int main() {
    int r, c, n;

    cout << "Enter rows, cols, nonZero count for Matrix A: ";
    cin >> r >> c >> n;
    auto A = readSparse(r, c, n);
    cout << "\nMatrix A:\n";
    printSparse(A);

    cout << "Transpose of A:\n";
    auto AT = transposeSparse(A);
    printSparse(AT);

    cout << "Enter rows, cols, nonZero count for Matrix B: ";
    cin >> r >> c >> n;
    auto B = readSparse(r, c, n);
    cout << "\nMatrix B:\n";
    printSparse(B);

    cout << "A + B:\n";
    auto SUM = addSparse(A, B);
    printSparse(SUM);

    cout << "A * B:\n";
    auto MUL = multiplySparse(A, B);
    printSparse(MUL);

    return 0;
}
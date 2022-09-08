#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void print(string display, vvi matrix,
           int start_row, int start_column, int end_row,
           int end_column)
{
    cout << endl
         << display << " =>" << endl;
    for (int i = start_row; i <= end_row; i++)
    {
        for (int j = start_column; j <= end_column; j++)
        {
            cout << setw(10);
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return;
}

vvi multiply_matrix(vvi &A, vvi &B, vvi &C, int ai, int aj, int bi, int bj, int ci, int cj, int n)
{
    if (n == 1)
    {
        C[ci][cj] += A[ai][aj] * B[bi][bj];
    }
    else
    {
        n /= 2;
        multiply_matrix(A, B, C, ai, aj, bi, bj, ci, cj, n);
        multiply_matrix(A, B, C, ai, aj + (n), bi + (n), bj, ci, cj, n);
        multiply_matrix(A, B, C, ai, aj, bi, bj + (n), ci, cj + (n), n);
        multiply_matrix(A, B, C, ai, aj + (n), bi + (n), bj + (n), ci, cj + (n), n);
        multiply_matrix(A, B, C, ai + (n), aj, bi, bj, ci + (n), cj, n);
        multiply_matrix(A, B, C, ai + (n), aj + (n), bi + (n), bj, ci + (n), cj, n);
        multiply_matrix(A, B, C, ai + (n), aj, bi, bj + (n), ci + (n), cj + (n), n);
        multiply_matrix(A, B, C, ai + (n), aj + (n), bi + (n), bj + (n), ci + (n), cj + (n), n);
    }
    return C;
}

int main()
{
    int n;
    cin >> n;
    int x = __builtin_popcount(n), extra = 0;
    if (x != 1)
        extra = round(pow(2, ceil(log2(n)))) - n;
    int N = n + extra;

    vvi result_matrix(N, vi(N, 0));
    vvi matrix_A(N, vi(N, 0));
    vvi matrix_B(N, vi(N, 0));

    cout << "Matrix_A\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j < n && i < n)
            {
                int num;
                cin >> num;
                matrix_A[i][j] += num;
            }
            else
                matrix_A[i][j] = 0;
        }
    }
    print("Array A", matrix_A, 0, 0, n - 1, n - 1);

    cout << "Matrix_B\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i < n && j < n)
            {
                int num;
                cin >> num;
                matrix_B[i][j] += num;
            }
            else
                matrix_B[i][j] = 0;
        }
    }

    print("Array B", matrix_B, 0, 0, n - 1, n - 1);

    result_matrix = multiply_matrix(matrix_A, matrix_B, result_matrix, 0, 0, 0, 0, 0, 0, N);
    print("Result Array", result_matrix, 0, 0, n - 1, n - 1);
}
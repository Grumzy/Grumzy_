#include <iostream>
#include <fstream>

using namespace std;

// G-J function for step-by-step matrix reduction
void gauss_jordan(int M, int N, double **A) {
    for (int k = 0; k < M; k++) {
        int i_max = k;
        double max = A[k][k];

        // This is used  to find a maximal element in k-column
        for (int i = k + 1; i < M; i++) {
            if (abs(A[i][k]) > abs(max)) {
                i_max = i;
                max = A[i][k];
            }
        }

        // Swap k-string with i_max-line
        for (int j = k; j <= N; j++) {
            double temp = A[k][j];
            A[k][j] = A[i_max][j];
            A[i_max][j] = temp;
        }

        // here is top triangular view
        for (int i = k + 1; i < M; i++) {
            double c = -A[i][k] / A[k][k];
            for (int j = k; j <= N; j++) {
                if (k == j) A[i][j] = 0;
                else A[i][j] += c * A[k][j];
            }
        }
    }

    // and here i diagonal view
    for (int k = M - 1; k >= 0; k--) {
        for (int i = k - 1; i >= 0; i--) {
            double c = -A[i][k] / A[k][k];
            for (int j = k; j <= N; j++) {
                if (k == j) A[i][j] = 0;
                else A[i][j] += c * A[k][j];
            }
        }
    }
    // some simplification
    for(int i = 0; i < M; i++)
    {
        A[i][N] /= A[i][i];
        A[i][i] = 1;
    }
}

int main() {
    ifstream fin("input.txt");
    int M, N;
    fin >> M >> N;

    double **A = new double*[M];
    for (int i = 0; i < M; i++) {
        A[i] = new double[N + 1];
        for (int j = 0; j <= N; j++) {
            fin >> A[i][j];
        }
    }

    // show matrix reduction function to step-like
    gauss_jordan(M, N, A);

    ofstream fout("output.txt");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j <= N; j++) {
            fout << A[i][j] << " ";
        }
        fout << endl;
    }
}

#include <iostream>
// We need to calculate A^N
using namespace std;

#define N 3
int arr[N][N];
int ide[N][N];

void printmat(int arr[][N], int dim) {
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void multiply(int A[][N], int B[][N], int dim) {
  int res[dim + 1][dim + 1];
  // Simple matrix multiplication.

  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      res[i][j] = 0;
      for (int k = 0; k < dim; k++) {
        res[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  // Storing the result back to A.

  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      A[i][j] = res[i][j];
    }
  }
}

void mat_exp(int arr[][N], int dim, int n) {
  // Creates an identity matrix
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      if (i == j) {
        ide[i][j] = 1;
      } else {
        ide[i][j] = 0;
      }
    }
  }

  //  mutliply identity with arr, result is in identity
  // Naive approach
  // for(int i=0; i<n; i++)
  // {
  //     multiply(ide, arr, dim);
  // }

  // Matrix exponentiation approach

  while (n > 0) {
    if (n % 2 == 0) {
      multiply(arr, arr, dim);
      n /= 2;
    } else {
      multiply(ide, arr, dim);
      n -= 1;
    }
  }

  // Make arr equal to identity
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j] = ide[i][j];
    }
  }

  // printmat(arr, dim);
}

int main() {
  int t, dim, n;
  cin >> t;
  while (t > 0) {
    cin >> dim >> n;
    for (int i = 0; i < dim; i++) {
      for (int j = 0; j < dim; j++) {
        cin >> arr[i][j];
      }
    }
    mat_exp(arr, dim, n);
    printmat(arr, dim);
    t -= 1;
  }
  return (0);
}

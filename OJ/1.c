#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MOD 1000000007  // 1e9+7

// Matrix multiplication: C = A * B (mod MOD)
void matrix_multiply(int A[MAX_N][MAX_N], int B[MAX_N][MAX_N], int C[MAX_N][MAX_N], int n) {
    int temp[MAX_N][MAX_N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < n; k++) {
                // Use long long to prevent overflow before taking modulo
                temp[i][j] = (temp[i][j] + (long long)A[i][k] * B[k][j] % MOD) % MOD;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = temp[i][j];
        }
    }
}

// Calculate A^k (mod MOD) using binary exponentiation
void matrix_power(int A[MAX_N][MAX_N], int result[MAX_N][MAX_N], int n, long long k) {
    int temp[MAX_N][MAX_N];
    int base[MAX_N][MAX_N];
    
    // Copy A to base since we'll be modifying A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            base[i][j] = A[i][j];
        }
    }
    
    // Initialize result as identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = (i == j) ? 1 : 0;
        }
    }
    
    // Binary exponentiation
    while (k > 0) {
        if (k % 2 == 1) {
            matrix_multiply(result, base, result, n);
        }
        matrix_multiply(base, base, base, n);
        k /= 2;
    }
}

// Solution for subpart 1: k = 2
void solve_k_equals_2(int adj[MAX_N][MAX_N], int result[MAX_N][MAX_N], int n) {
    // For k=2, we just need to compute adj^2
    matrix_multiply(adj, adj, result, n);
}

// Solution for subpart 2: k <= 30
// Solution for subpart 3: k <= 10^9
// Both use the same approach with binary exponentiation
void solve_k_general(int adj[MAX_N][MAX_N], int result[MAX_N][MAX_N], int n, long long k) {
    matrix_power(adj, result, n, k);
}

int main() {
    int n;
    long long k;
    int adj[MAX_N][MAX_N];
    int result[MAX_N][MAX_N];
    
    // Read input
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    scanf("%lld", &k);
    
    // Choose the appropriate solution based on k
    if (k == 2) {
        solve_k_equals_2(adj, result, n);
    } else {
        solve_k_general(adj, result, n, k);
    }
    
    // Print result matrix
    int total_paths = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            total_paths = (total_paths + result[i][j]) % MOD;
        }
    }
    
    printf("%d\n",total_paths);
    
    return 0;
}
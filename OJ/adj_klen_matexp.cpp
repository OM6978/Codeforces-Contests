#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX_N = 100;

typedef vector<vector<int>> Matrix;

Matrix multiply(const Matrix &A, const Matrix &B, int n)
{
    Matrix C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    return C;
}

Matrix power(Matrix & A, long long k, int n)
{
    Matrix res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1;
    
    while (k > 0)
    {
        if (k & 1) res = multiply(res, A, n);
        A = multiply(A, A, n);
        k >>= 1;
    }

    return res;
}

void solve()
{
    int n; long long k;
    cin >> n >> k;
    Matrix adj(n, vector<int>(n));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
    
    Matrix result = power(adj, k, n);
    
    int total_paths = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            total_paths = (total_paths + result[i][j]) % MOD;
        }
    }
    
    cout << total_paths << "\n";
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/OJ/subpart2_test_case_5.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/OJ/subpart2_output5.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();
    
    return 0;
}

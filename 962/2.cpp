#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,K;
    cin>>N>>K;

    int mat[N][N];
    for(int i=0;i<N;i++)
    {
        string inp;
        cin>>inp;

        for(int j=0;j<N;j++)
        {
            mat[i][j] = inp[j] - '0';
        }
    }

    int ans[N/K][N/K];

    for(int i=0;i<N/K;i++)
    {
        for(int j=0;j<N/K;j++)
        {
            cout << mat[i*K][j*K];
        }
        cout<<'\n';
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
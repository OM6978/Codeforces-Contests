#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    int mat[N][N];
    int dias[2*N-1];
    for(int i=0;i<2*N-1;i++)dias[i] = 0;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>mat[i][j];
            if(mat[i][j] < 0)dias[j+N-1-i] = max(dias[j+N-1-i],-mat[i][j]);
        }
    }
    
    int ans = 0;
    for(int i=0;i<2*N-1;i++)
    {
        ans+= dias[i];
    }
    cout << ans << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
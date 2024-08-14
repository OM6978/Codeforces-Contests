#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

void solve()
{
    int N,M;
    cin>>N>>M;

    int mat[N][M];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)cin>>mat[i][j];
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int temp = -(1<<30);
            if(i!=0)temp = max(temp,mat[i-1][j]);
            if(i!=N-1)temp = max(temp,mat[i+1][j]);
            if(j!=M-1)temp = max(temp,mat[i][j+1]);
            if(j!=0)temp = max(temp,mat[i][j-1]);

            mat[i][j] = min(mat[i][j],temp);
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)cout<<mat[i][j]<<spc;
        cout<<endl;
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
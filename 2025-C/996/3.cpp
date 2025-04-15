#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,M;
    cin>>N>>M;

    string s;
    cin>>s;

    int mat[N][M];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>mat[i][j];
        }
    }

    int colsum[M],rowsum[N];
    for(int i=0;i<N;i++)
    {
        rowsum[i] = 0;
    }

    for(int j=0;j<M;j++)
    {
        colsum[j] = 0;
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            rowsum[i]+=mat[i][j];
        }
    }

    for(int j=0;j<M;j++)
    {
        for(int i=0;i<N;i++)
        {
            colsum[j]+=mat[i][j];
        }
    }

    int i = 0,j = 0,z;

    int y = s[0];
    if(y == 'D')i++,mat[0][0]=-rowsum[0];
    else j++,mat[0][0] = -colsum[0];

    z=0;
    colsum[0]+=mat[0][0];
    rowsum[0]+=mat[0][0];

    for(int k = 1;k<s.size();k++)
    {
        int x = s[k];
        if(x == 'D')
        {
            mat[i][j] = z - rowsum[i];
        }
        else
        {
            mat[i][j] = z - colsum[j];
        }

        colsum[j]+=mat[i][j];
        rowsum[i]+=mat[i][j];

        if(s[k] == 'D')i++;
        else j++;
    }

    mat[N-1][M-1] = z - rowsum[N-1];

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cout<<mat[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
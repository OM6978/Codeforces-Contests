#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '

void solve()
{
    int N,M;
    cin>>N>>M;

    int mat[N][M],temp[N][M];
    string s;
    for(int i=0;i<N;i++)
    {
        cin>>s;
        for(int j=0;j<M;j++)
        {
            temp[i][j] = s[j] - '0';
        }
    }

    int cols[M][2],rows[N][2];
    for(int i=0;i<N;i++)rows[i][0] = 0,rows[i][1] = 0;
    for(int i=0;i<N;i++)cols[i][0] = 0,cols[i][1] = 0;

    for(int i=0;i<N;i++)
    {
        cin>>s;
        for(int j=0;j<M;j++)
        {
            mat[i][j] = (s[j] - '0' - temp[i][j] + 3)%3;
            if(mat[i][j])
            {
                cols[j][mat[i][j]-1]++;
                rows[i][mat[i][j]-1]++;
            }
        }
    }

    for(int i=0;i<N;i++)
    {
        if(rows[i][0] != rows[i][1]){cout<<"NO"<<endl;return;}
    }

    for(int i=0;i<M;i++)
    {
        if(cols[i][0] != cols[i][1]){cout<<"NO"<<endl;return;}
    }

    cout<<"YES"<<endl;
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
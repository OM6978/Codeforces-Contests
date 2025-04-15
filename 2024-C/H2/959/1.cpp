#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '

void solve()
{
    int N,M;
    cin>>N>>M;

    int temp;
    if(N == 1 && M==1){cin>>temp;cout<<-1<<endl;return;}

    int a[N][M],b[N][M];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>a[i][j];

            if(a[i][j] != (N*M))b[i][j] = (a[i][j] + 1)%(N*M+1);
            else b[i][j] = 1;

            cout<<b[i][j]<<sp;
        }
        cout<<endl;
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
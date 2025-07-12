#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,Q;
    cin>>N>>Q;

    vector<vector<int>> mat(N,vector<int>(N));
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;

        for(int j=0;j<N;j++)
        {
            mat[i][j] = s[j];
        }
    }

    vector<vector<int>> prex(N,vector<int>(N,0));
    vector<vector<int>> prey(N,vector<int>(N,0));

    for(int i=0;i<N;i++)
    {
        prex[i][0] = (mat[i][0] == '*');
        for(int j=1;j<N;j++)
        {
            prex[i][j] = prex[i][j-1] + (mat[i][j] == '*');
        }
    }

    for(int j=0;j<N;j++)
    {
        prey[0][j] = prex[0][j];
        for(int i=1;i<N;i++)
        {
            prey[i][j] = prey[i-1][j] + prex[i][j];
        }
    }

    while(Q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        x1--,x2--,y1--,y2--;
        
        int lx = min(x1,x2);
        int rx = max(x1,x2);

        int ans = 0;
        if(y1 > y2)
        {
            swap(y1,y2);
        }
        
        if(lx!=0)ans-= prey[lx-1][y2];
        ans+= prey[rx][y2];

        if(y1!=0)
        {
            if(lx!=0)ans+= prey[lx-1][y1-1];
            ans -= prey[rx][y1-1];
        }

        cout << ans << '\n';
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
    
    solve();

    return 0;
}
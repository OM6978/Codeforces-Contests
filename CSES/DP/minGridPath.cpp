#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int N;
    cin>>N;

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
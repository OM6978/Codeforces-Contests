#include <bits/stdc++.h>
using namespace std;
    
void solve()
{
    int N,M,Q;
    cin>>N>>M>>Q;
    
    vector<vector<int>> arr(N,vector<int>(M));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>arr[i][j];
        }
    }
    
    vector<vector<int>> mat(M,vector<int>(N));
    
    for(int i=0;i<M;i++)
    {
        mat[i][0] = arr[0][i];
        for(int j=1;j<N;j++)
        {
            mat[i][j] = (mat[i][j-1] | arr[j][i]);
        }
    }
    
    while(Q--)
    {
        int l = 0,r = N-1;
    
        int T;
        cin>>T;
    
        while(T--)
        {
            int a,c;
            char b;
            cin>>a>>b>>c;
            a--;
    
            vector<int> & v = mat[a];
    
            if(b == '>')
            {
                int x = upper_bound(v.begin(),v.end(),c) - v.begin();
                l = max(l,x);
            }
            else
            {
                int x = lower_bound(v.begin(),v.end(),c) - v.begin();
                x--;
    
                r = min(r,x);
            }
        }
    
        cout << ((l > r)?-1:l+1) << '\n';
    }
}
    
signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}
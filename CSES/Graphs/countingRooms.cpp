#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> chngs = {{1,0},{0,1},{-1,0},{0,-1}};

int isValid(int i,int j,int N,int M)
{
    return (i>=0 && i<N && j>=0 && j<M);
}

int numIslands(int row,int col,vector<vector<int>> & mat,vector<vector<int>> & vis)
{
    int N = mat.size(),M = mat[0].size();
    if(vis[row][col])return 0;

    vis[row][col] = 1;
    if(mat[row][col] == '.')
    {
        for(auto [di,dj] : chngs)
        {
            if(isValid(row+di,col+dj,N,M))
            {
                numIslands(row+di,col+dj,mat,vis);
            }
        }

        return 1;
    }
    else
    {
        return 0;
    }
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> mat(N,vector<int>(M));
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;

        for(int j=0;j<M;j++)
        {
            mat[i][j] = s[j];
        }
    }

    vector<vector<int>> vis(N,vector<int> (M,0));

    int ans = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            ans += numIslands(i,j,mat,vis);
        }
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
    cin.tie(NULL);cout.tie(NULL);
    
    solve();
    
    return 0;
}
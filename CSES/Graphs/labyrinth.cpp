#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> chngs = {{1,0},{0,1},{-1,0},{0,-1}};
map<pair<int,int>,int> chngDict = {{{1,0},'D'},{{0,1},'R'},{{-1,0},'U'},{{0,-1},'L'}};

int isValid(int i,int j,int N,int M)
{
    return (i>=0 && i<N && j>=0 && j<M);
}

string currPath;
int best = 1e9;

int findPath(int steps,int row,int col,vector<vector<int>> & mat,vector<vector<int>> & vis)
{
    int N = mat.size(),M = mat[0].size();
    if(vis[row][col] || mat[row][col] == '#')return 0;
    if(mat[row][col] == 'B')
    {
        if(steps < best)
        {
            currPath.clear();
            best = steps;
            return 1;
        }
        return 0;
    }

    int ret = 0;
    vis[row][col] = 1;
    for(auto [di,dj] : chngs)
    {
        if(isValid(row+di,col+dj,N,M))
        {
            if(findPath(steps+1,row+di,col+dj,mat,vis))
            {
                currPath.push_back(chngDict[{di,dj}]);
                ret=1;
            }
        }
    }
    
    return ret;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> mat(N,vector<int>(M));

    int sr,sc;
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;

        for(int j=0;j<M;j++)
        {
            mat[i][j] = s[j];
            if(s[j] == 'A')
            {
                sr = i;
                sc = j;
            }
        }
    }

    vector<vector<int>> vis(N,vector<int> (M,0));

    if(findPath(0,sr,sc,mat,vis))
    {
        cout << "YES\n";
        reverse(currPath.begin(),currPath.end());
        cout << currPath.size() << '\n';
        cout << currPath << '\n';
    }
    else
    {
        cout << "NO\n";
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
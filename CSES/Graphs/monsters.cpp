#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> chngs = {{1,0},{0,1},{-1,0},{0,-1}};
map<pair<int,int>,int> chngDict = {{{1,0},'D'},{{0,1},'R'},{{-1,0},'U'},{{0,-1},'L'}};

vector<vector<pair<int,int>>> par(1000,vector<pair<int,int>> (1000));

bool isValid(int i,int j,vector<vector<int>> & mat,vector<vector<int>> & vis)
{
    int N = mat.size(),M=mat[0].size();
    return (i>=0 && i<N && j>=0 && j<M && mat[i][j] != '#' && vis[i][j] == 0);
}

bool findPath(int steps,int row,int col,vector<vector<int>> & mat)
{
    int N = mat.size(),M = mat[0].size();
    vector<vector<int>> vis(N,vector<int> (M,0));

    queue<pair<int,int>> q;
    q.push({row,col});

    bool found = false;
    while(q.size() && !found)
    {
        int cnt = q.size();
        while(cnt--)
        {
            auto [x,y] = q.front();
            q.pop();

            if(vis[x][y])continue;
            vis[x][y] = 1;

            if(mat[x][y] == 'B')
            {
                found = true;
                break;
            }

            for(auto [dx,dy] : chngs)
            {
                int xx = x + dx;
                int yy = y + dy;

                if(!isValid(xx,yy,mat,vis))continue;

                q.push({xx,yy});

                par[xx][yy] = {x,y};
            }
        }

        if(found)break;
    }

    return found;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> mat(N+1,vector<int>(M+1));

    int sr,sc,er,ec;
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
            if(s[j] == 'B')
            {
                er = i;
                ec = j;
            }
        }
    }

    
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/Om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/Om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();

    return 0;
}
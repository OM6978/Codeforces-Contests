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

bool findPath(int row,int col,vector<vector<int>> & mat)
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

void finddist(vector<pair<int,int>> & P,vector<vector<int>> & mat,vector<vector<int>> & dist)
{
    int N = mat.size(),M = mat[0].size();
    vector<vector<int>> vis(N,vector<int> (M,0));

    queue<pair<int,int>> q;
    for(auto [sx,sy] : P)
    {
        q.push({sx,sy});
        vis[sx][sy] = 1;
    }

    int d = 0;
    while(q.size())
    {
        int cnt = q.size();
        while(cnt--)
        {
            auto [x,y] = q.front();q.pop();

            dist[x][y] = min(dist[x][y],d);

            for(auto [dx,dy] : chngs)
            {
                int nx = x + dx,ny = y + dy;
                if(isValid(nx,ny,mat,vis))
                {
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
        }

        d++;
    }
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> mat(N,vector<int>(M));
    vector<pair<int,int>> monsters;

    int sx,sy;
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;

        for(int j=0;j<M;j++)
        {
            mat[i][j] = s[j];
            if(mat[i][j] == 'M')
            {
                monsters.push_back({i,j});
            }
            if(mat[i][j] == 'A')sx=i,sy=j;
        }
    }

    vector<vector<int>> dist1(N,vector<int>(M,1e9));
    vector<vector<int>> dist2(N,vector<int>(M,1e9));

    finddist(monsters,mat,dist1);

    vector<pair<int,int>> start = {make_pair(sx,sy)};
    finddist(start,mat,dist2);

    int ex=-1,ey=-1;
    for(int i=0;i<N;i++)
    {
        if(dist1[i][0] > dist2[i][0])
        {
            ex=i;
            ey=0;
        }
        else if(dist1[i][M-1] > dist2[i][M-1])
        {
            ex=i;
            ey=M-1;
        }
    }

    for(int j=0;j<M;j++)
    {
        if(dist1[0][j] > dist2[0][j])
        {
            ex=0;
            ey=j;
        }
        else if(dist1[N-1][j] > dist2[N-1][j])
        {
            ex=N-1;
            ey=j;
        }
    }

    if(ex==-1)cout << "NO\n";
    else
    {
        cout << "YES\n";
        if(mat[ex][ey] == 'A')
        {
            cout << 0 << '\n';
            return;
        }

        mat[ex][ey] = 'B';
        findPath(sx,sy,mat);

        string path;
        while(mat[ex][ey] != 'A')
        {
            auto [sx,sy] = par[ex][ey];
            path.push_back(chngDict[{ex-sx,ey-sy}]);

            ex = sx;
            ey = sy;
        }

        reverse(path.begin(),path.end());
        cout << path.size() << '\n';
        cout << path << '\n';
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

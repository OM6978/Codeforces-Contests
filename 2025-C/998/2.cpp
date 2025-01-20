#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>>& mat, vector<vector<int>>& res)
{
    int rows = mat.size();      
    int cols = mat[0].size();   

    res.resize(cols, vector<int>(rows));

    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            res[j][i] = mat[i][j]; 
        }
    }
}

bool check(vector<int> & perm,vector<vector<int>> & mat)
{
    int last = -1;
    int N = mat.size(),M = mat[0].size();

    for(int j=0;j<M;j++)
    {
        for(int i=0;i<N;i++)
        {
            if(last > mat[perm[i]][j])
            {
                return false;
            }
            last = mat[perm[i]][j];
        }
    }

    return true;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> mat(N,vector<int> (M));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>mat[i][j];
        }

        sort(mat[i].begin(),mat[i].end());
    }

    vector<vector<int>> res;
    transpose(mat,res);

    auto v = res[0];
    multiset<pair<int,int>> ms;
    for(int i=0;i<N;i++)ms.insert({v[i],i});

    vector<int> perm;
    for(auto &[x,y] : ms)
    {
        perm.push_back(y);
    }

    if(check(perm,mat))
    {
        for(int x : perm)
        {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
    else
    {
        cout << -1 << '\n';
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
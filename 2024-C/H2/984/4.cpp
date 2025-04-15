#include <bits/stdc++.h>
using namespace std;

pair<int,int> get_ints(int i,int j,int N,int M)
{
    pair<int,int> x = {0,N-1};
    pair<int,int> y = {0,M-1};

    int lvl= i - x.first,typ=0;

    if(y.second - j < lvl)
    {
        lvl = y.second - j;
        typ = 1;
    }
    if(x.second - i < lvl)
    {
        lvl = x.second - i;
        typ = 2;
    }
    if(j - y.first < lvl)
    {
        lvl = j - y.first;
        typ = 3;
    }

    return {lvl,typ};
}

pair<int,int> perf(int lvl,int & typ,int i,int j,int N,int M)
{
    if(typ == 0)j++;
    else if(typ == 1)i++;
    else if(typ == 2)j--;
    else i--;

    auto [li,t] = get_ints(i,j,N,M);
    if(li != lvl)
    {
        typ = (typ + 1)%4;
        return {-1,-1};
    }

    return {i,j};
}

void nextind(int lvl,int & typ,int & i,int & j,int N,int M)
{
    auto p = perf(lvl,typ,i,j,N,M);
    if(p.first == -1)p = perf(lvl,typ,i,j,N,M);

    i = p.first;
    j = p.second;
}

bool isbeut(int i,int j,vector<string> & mat)
{
    int N = mat.size(),M = mat[0].size();
    auto [lvl,typ] = get_ints(i,j,N,M);

    if(mat[i][j] != '1')return false;
    nextind(lvl,typ,i,j,N,M);

    if(mat[i][j] != '5')return false;
    nextind(lvl,typ,i,j,N,M);

    if(mat[i][j] != '4')return false;
    nextind(lvl,typ,i,j,N,M);

    if(mat[i][j] != '3')return false;
    else return true;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<string> mat(N);

    for(int i=0;i<N;i++)cin>>mat[i];

    int count = 0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(isbeut(i,j,mat))count++;

    cout << count << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
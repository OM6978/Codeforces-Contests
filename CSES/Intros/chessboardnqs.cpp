#include <bits/stdc++.h>
using namespace std;

int getways(int i,vector<int> & cols,vector<int> & diag1,vector<int> & diag2,vector<string> & mat)
{
    if(i==8)
    {
        return 1;
    }

    int ways = 0;
    for(int j=0;j<8;j++)
    {
        if(mat[i][j] == '*')continue;

        if(cols[j] == 0 && diag1[i+j]==0 && diag2[i-j+7]==0)
        {
            cols[j] = 1;
            diag1[i+j] = 1;
            diag2[i-j+7] = 1;

            ways += getways(i+1,cols,diag1,diag2,mat);

            cols[j] = 0;
            diag1[i+j] = 0;
            diag2[i-j+7] = 0;
        }
    }

    return ways;
}

void solve()
{
    vector<string> mat(8);
    for(int i=0;i<8;i++)
    {
        cin>>mat[i];
    }

    vector<int> cols(8,0),diag1(15,0),diag2(15,0);

    cout << getways(0,cols,diag1,diag2,mat) << '\n';
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
#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

void solve()
{
    int x, y;
    cin >>x>> y;

    int cells_1x1=x;

    int cells_2x2=y*4,screens=y;
    
    cells_2x2-=screens * 9;

    if (cells_2x2 > 0)
      screens += (cells_2x2 + 4 - 1) / 4;

    screens += (cells_1x1 + 4 - 1) / 4;

    cout << screens << endl;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
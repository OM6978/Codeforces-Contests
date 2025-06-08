#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    // if corner then k*k - 2
    // if double corner edge then k*k - 2
    // if corner edge then k*k - 3
    // if edge then k*k - 4
    // if corner second edge then k*k - 4
    // if second edge then k*k - 6
    // else k*k - 8

    // n <= 2 return 0
    // corners = 4
    // double corner edge = (n==3)*4

    // n==3 return sum + 8

    // corner edge = 8
    // edge = 4*(k-1) - corners - corner edge
    // corner second edge = 4
    // second edge = 4*(k-3) - 4
    // elses = (k-4)*(k-4)

    int N;
    cin>>N;

    for(int k=1;k<=N;k++)
    {
        if(k<=3)
        {
            if(k==1)cout << 0 << '\n';
            else if(k==2)cout << 6 << '\n';
            else cout << 28 << '\n';
            continue;
        }

        int corns = 4;
        int cedge = 8;
        int edge = 4*(k-1) - 12;
        int csedge = 4;
        int sedge = 4*(k-3) - 4;
        int rest = (k-4)*(k-4);

        cout << (corns*(k*k - 3) + cedge*(k*k - 4) + edge*(k*k - 5) + csedge*(k*k-5) + sedge*(k*k - 7) + rest*(k*k - 9)) / 2 << '\n';
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
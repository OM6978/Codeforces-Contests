#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    string A,B;
    cin>>A>>B;

    int choices = 0,ones = 0;
    for(int i=0;i<N;i++)
    {
        if(A[i] == B[i])
        {
            if(A[i]=='1')ones++;
        }
        else choices++;
    }

    if(choices > 0 || ones%2 == 1)cout << "YES\n";
    else cout << "NO\n";
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
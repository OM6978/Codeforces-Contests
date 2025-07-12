#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    int ar[N],br[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    int least = 1e16,needed = 0,times = 0;
    for(int i=0;i<N;i++)
    {
        cin>>br[i];
        if(br[i] > ar[i])times++,needed+= br[i] - ar[i];
        else
        {
            least = min(ar[i] - br[i],least);
        }
    }

    if(times > 1 || needed > least)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
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
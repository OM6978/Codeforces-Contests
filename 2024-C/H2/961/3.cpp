#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    int ops = 0;
    pair<double,int> last = {log2(ar[0]),0};
    for(int i=1;i<N;i++)
    {
        if(ar[i] == 1)
        {
            if(last.first == 0)continue;
            ops = -1;
            break;
        }
        else
        {
            double y = log2(ar[i]);
            if(last.first == 0)
            {
                last = {y,0};
                continue;
            }

            auto lol = last.first/y;
            lol = log2(lol);
            double x = (double)last.second + lol;

            x = ceil(x);
            if(x <= 0)
            {
                last = {y,0};
            }
            else
            {
                last = {y,x};
                ops += x;
            }
        }
        
    }

    cout << ops << '\n';
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
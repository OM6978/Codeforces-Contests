#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    int ops = 0,last = 0;
    if(ar[0] >2)ops++;
    else if(ar[0] >= 1)
    {
        ops++;
        last=1;
    }

    for(int i=1;i<N;i++)
    {
        if(last == 0)
        {
            if(ar[i] >2)ops++;
            else if(ar[i] >= 1)
            {
                ops++;
                last=1;
            }
        }
        else if(last == 1)
        {
            if(ar[i] > 4)
            {
                last = 0;
                ops++;
            }
            else if(ar[i] > 2)
            {
                ops++;
                last = 2;
            }
            else last = 0;
        }
        else
        {
            if(ar[i] > 4)
            {
                last = 0;
                ops++;
            }
            else if(ar[i] > 0)
            {
                last = 1;
                ops++;
            }
            else last = 0;
        }
    }

    cout<<ops<<'\n'; 
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
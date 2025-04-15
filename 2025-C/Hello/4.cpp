#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,q;
    cin>>n>>q;

    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    set<pair<int,int>> minsfw,maxssfw;
    set<pair<int,int>> minsbw,maxssbw;

    int least=ar[0],most=ar[0],ans = 0;
    int in1 = 0,in2 = 0;
    for(int i=1;i<n;i++)
    {
        least++,most--;

        if(least > ar[i])
        {
            minsfw.insert({in1,i - in1});
            least = ar[i],in1 = i;
        }
        if(most < ar[i])
        {
            maxssfw.insert({in2,i - in2});
            most = ar[i],in2 = i;
        }

        ans = max(ans,most - least);
    }

    least=ar[n-1],most=ar[n-1];
    in1 = n-1,in2 = n-1;
    for(int i=n-2;i>=0;i--)
    {
        least++,most--;

        if(least > ar[i])
        {
            minsbw.insert({in1,in1 - i});
            least = ar[i],in1 = i;
        }
        if(most < ar[i])
        {
            maxssfw.insert({in2,in2 - i});
            most = ar[i],in2 = i;
        }
    }

    cout << ans << '\n';

    while(q--)
    {
        int p,x;
        cin>>p>>x;

        {
            auto it = lower_bound(minsfw.begin(),minsfw.end(),p-1);

            if(it != minsfw.end())
            {
                auto [in,len] = *it;
                
                if(ar[in] > x)

            }
        }

        ar[p-1] = x;
        cout << ans << '\n';
    }
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
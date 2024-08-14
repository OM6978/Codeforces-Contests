#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '

void solve()
{
    int N,l,r;
    cin>>N>>l>>r;

    int ar[N],ans=0;
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];

        if(ar[i] > r)ar[i] = -1;
        else if(ar[i] >= l)
        {
            ar[i] = -1;
            ans++;
        }
    }

    int currs = 0,in=-1;
    for(int i=0;i<N;i++)
    {
        // cout<<currs<<endl;
        if(ar[i] == -1){in = -1;currs=0;continue;}

        if(in == -1)in = i;
        currs+=ar[i];

        while(currs > r)currs-= ar[in++];

        if(currs >= l)
        {
            ans++;
            currs=0;
            in=-1;
        }
    }

    cout<<ans<<endl;
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
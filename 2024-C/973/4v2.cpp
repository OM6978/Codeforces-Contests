#include <bits/stdc++.h>
using namespace std;

#define int long long

bool good1(int mid,int* ar,int N)
{
    int bank = 0;
    for(int i=N-1;i>=0;i--)
    {
        bank+= (mid - ar[i]);
        if(bank < 0)return false;
    }

    return true;
}

bool good2(int mid,int* ar,int N)
{
    int bank = 0;
    for(int i=0;i<N;i++)
    {
        bank += (ar[i] - mid);
        if(bank < 0)return false;
    }

    return true;
}

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    for(int i=0;i<N;i++)cin>>ar[i];

    int most;
    {
        int l = -1,r = 1e12;
        while(l+1<r)
        {
            int mid = (l+r)/2;
            if(good1(mid,ar,N))r = mid;
            else l = mid;
        }
        most = r;
    }

    int least;
    {
        int l = 0,r = 1e12+1;
        while(l+1<r)
        {
            int mid = (l+r)/2;
            if(good2(mid,ar,N))l = mid;
            else r = mid;
        }
        least = l;
    }
    
    cout << most - least << '\n';
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
#include <bits/stdc++.h>
using namespace std;

#define int long long

int find_b_sum(int l,int r,int* pref,int* pref2)
{
    int ret=0;

    ret += pref2[r];
    if(l!=0)ret -= pref2[l-1] + pref[l-1]*(r-l+1);

    return ret;
}

int get_s(int a,int N)
{
    return (a*(2*N - (a-1)))/2;
}

pair<int,int> get_limit(int a,int N)
{
    int l = 0,r = N;
    while(l+1<r)
    {
        int mid = (l+r)/2;
        if(get_s(mid,N)<=a)l = mid;
        else r = mid;
    }

    return {l,a - get_s(l,N)};
}

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    for(int i=0;i<N;i++)cin>>ar[i];

    int pref[N];
    pref[0] = ar[0];
    for(int i=1;i<N;i++)pref[i] = pref[i-1] + ar[i];

    int pref2[N];
    pref2[0] = pref[0];
    for(int i=1;i<N;i++)pref2[i] = pref2[i-1] + pref[i];

    int pref3[N];
    pref3[0] = find_b_sum(0,N-1,pref,pref2);
    for(int i=1;i<N;i++)pref3[i] = find_b_sum(i,N-1,pref,pref2) + pref3[i-1];

    int Q;
    cin>>Q;

    while(Q--)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;

        auto [l1,l2] = get_limit(l,N);
        auto [r1,r2] = get_limit(r,N);

        // cout << l1 << ' ' << l2 << ' ' << r1 << ' ' << r2 << '\n';

        int ans = 0;

        if(r1 > l1)
        {
            ans += pref3[r1-1];
            ans -= pref3[l1];
        }

        if(r1 != l1)
        {
            ans += find_b_sum(r1,r2+r1,pref,pref2);
            ans += find_b_sum(l1,N-1,pref,pref2);
        }
        else ans += find_b_sum(l1,l1+r2,pref,pref2);

        if(l2!=0)ans -= find_b_sum(l1,l1 + l2-1,pref,pref2);

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
    
    solve();
    
    return 0;
}
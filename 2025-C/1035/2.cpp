#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define int long long

ld dist(int p1,int p2,int q1,int q2)
{
    return sqrt((ld)((p1 - q1)*(p1 - q1) + (p2 - q2)*(p2 - q2)));
}

void solve()
{
    int N;
    cin>>N;

    int p1,p2,q1,q2;
    cin>>p1>>p2>>q1>>q2;

    ld r=dist(p1,p2,q1,q2);
    int sum=0;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        sum+=ar[i];
    }

    for(int i=0;i<N;i++)
    {
        if(abs(r - ar[i]) > sum - ar[i])
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
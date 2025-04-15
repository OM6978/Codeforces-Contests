#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    sort(ar.begin(),ar.end());

    vector<int> v(N);
    for(int i=0;i<N;i+=2)
    {
        v[i] = ar[i/2];
        if(i!=N-1)v[i+1] = ar[(N+1)/2 + i/2];
    }

    for(int i=0;i<N;i++)
    {
        int prev = v[(i-1 + N) % N];
        int next = v[(i + 1)%N];

        if(!((prev < v[i] && next < v[i]) || (prev > v[i] && next > v[i])))
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    // for(int x : v)
    // {
    //     cout << x << ' ';
    // }
    // cout << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/OJ/testcases_10.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/OJ/output_10.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
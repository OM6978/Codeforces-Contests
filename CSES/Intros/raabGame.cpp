#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,a,b;
    cin>>N>>a>>b;

    int sum = a + b;
    if(sum!=0 && (sum==1 || sum>N || a == sum || b == sum))
    {
        cout << "NO\n";
        return;
    }
    else
    {
        cout << "YES\n";
    }

    vector<int> A,B;
    for(int i=N;i>sum;i--)
    {
        A.push_back(i);
        B.push_back(i);
    }

    N = sum;
    for(int i=0;i<a;i++)
    {
        A.push_back(N-i);
        B.push_back(a - i);
    }

    for(int i=0;i<b;i++)
    {
        A.push_back(b-i);
        B.push_back(N-i);
    }

    for(int x : A)
    {
        cout << x << ' ';
    }
    cout << '\n';
    for(int x : B)
    {
        cout << x << ' ';
    }
    cout << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Downloads/test_input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
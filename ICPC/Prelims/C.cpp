#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> SieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    vector<int> ans;

    for (int p = 2; p <= n; p++)
        if (prime[p])
            ans.push_back(p);

    return ans;
}

vector<int> primes;

void solve()
{
    int N,K;
    cin>>N>>K;

    int curr = 0;
    vector<int> ans = {primes[0]};

    int i;
    for(i=1;curr<=K;i++)
    {
        curr+=i;
        ans.push_back(primes[i]);
    }
    curr-=i-1;
    ans.pop_back();

    auto prev = ans;

    int left = K - curr;
    for(i=1;i<=left;i++)
    {
        ans[i]*=prev[i-1];
    }

    for(int x : ans)cout << x << ' ';
    cout << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    primes = SieveOfEratosthenes(2e6+1);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9 + 7;
int fac[(int)(2e5+1)];

int power(int x, int y, int p)
{
    int res = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
        res = (res * x)%p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res % p;
}

int modInverse(unsigned long long n,  int MOD)
{
    return power(n, MOD - 2, MOD);
}

int Combinator(int N,int K)
{
    return ((((fac[N] * modInverse(fac[K], MOD) )% MOD)* modInverse(fac[N - K], MOD)) % MOD)% MOD;
}

void solve()
{
    int N,K;
    cin>>N>>K;

    int ar[N],ones = 0;
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        ones+=ar[i];
    }

    int sum = 0;
    for(int i=min(ones,K);i >= max((K/2) + 1,K-(N - ones));i--)
    {
        sum = (sum + (Combinator(ones,i)*Combinator(N-ones,K-i))%MOD)%MOD;
    }

    cout<<sum<<'\n';
}

void calcFactorial()
{
    fac[0] = 1;
    for(int i=1;i<2e5+1;i++)
    {
        fac[i] = (fac[i-1] * i)%MOD;
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    calcFactorial();

    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
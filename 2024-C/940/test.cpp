#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>
#define int long long

int fac[301],MOD = 2e9+7;

void calcFactorial()
{
    fac[0] = 1;
    for(int i=1;i<301;i++)
    {
        fac[i] = fac[i-1]*i;
    }
}

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

signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    calcFactorial();

    cout<< (fac[5] * modInverse(fac[2],MOD))%MOD<<endl;

    return 0;
}
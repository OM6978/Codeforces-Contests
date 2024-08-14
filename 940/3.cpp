#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>
#define int long long

int MOD = 1e9 + 7;

int triangleperms[(int)(3e5 + 1)];
int fac[(int)(3e5+1)];

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

int gettriangleperms(int Num)
{
    if(Num<=0)return 1;

    return triangleperms[Num];
}

int calcboardperms(int Num)
{
    if(Num==0)return 1;

    int ans=0;
    for(int i=0 + (Num&1);i<=Num;i+=2)
    {
        ans= (ans + (Combinator(Num,i)*(gettriangleperms(Num - i -1)*power(2,(Num-i)/2,MOD)%MOD))%MOD)%MOD;
    }
    return ans;
}

void solve()
{
    int N,K;
    cin>>N>>K;

    int temp1,temp2,left=N;
    for(int i=0;i<K;i++)
    {
        cin>>temp1>>temp2;
        if(temp1!=temp2)left-=2;
        else left-=1;
    }

    int ans = calcboardperms(left);

    cout<<ans<<endl;
}

void calctriangleperms()
{
    triangleperms[1] = 1;
    for(int i=3;i<=3e5+1;i+=2)
    {
        triangleperms[i] = (triangleperms[i-2] * i)%MOD;
    }
}

void calcFactorial()
{
    fac[0] = 1;
    for(int i=1;i<3e5+1;i++)
    {
        fac[i] = (fac[i-1] * i)%MOD;
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    calctriangleperms();
    calcFactorial();
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string sv,bv;
ll n;
ll dp[20][2][2][200];

ll dfs(ll i,bool b1,bool b2,ll sum)
{
    if(sum<0 || sum>9*(n-i))return 0;
    if(i==n)return sum==0;

    if(dp[i][b1][b2][sum]!=-1)return dp[i][b1][b2][sum];
    ll ans=0;
    
    for(auto j='0';j<='9';j++)
    {
        if(!b1&&j<sv[i]) continue;
        if(!b2&&j>bv[i]) continue;
        ans+=dfs(i+1,b1||j>sv[i],b2||j<bv[i],sum-(j-'0'));
    }
    return dp[i][b1][b2][sum]=ans;
}

vector<ll> solve(ll s,ll b)
{
    while(s)
    {
        sv.push_back(s%10 +'0');
        s/=10;
    }
    while(b)
    {
        bv.push_back(b%10 + '0');
        b/=10;
    }

    while(sv.size()!=bv.size())sv.push_back('0');

    reverse(sv.begin(),sv.end());
    reverse(bv.begin(),bv.end());

    ll fans=-1,fsum=0;
    memset(dp,-1,sizeof(dp));
    n=bv.size();

    for(ll i=0;i<=9*bv.size();i++)
    {
        ll ans=dfs(0,0,0,i);
        if(ans>fans)
        {
            fans=ans;
            fsum=1;
        }
        else if(ans==fans)
            fsum++;
    }

    return (vector<ll>){fsum,fans};
}

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> lol = solve(0,1);
    cout<<lol[0]<<' '<<lol[1]<<'\n';

	return 0;
}
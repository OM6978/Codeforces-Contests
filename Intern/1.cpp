#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '
#define int long long

void solve()
{
    int N;
    cin>>N;

    int ar[N],br[N],sum=0;
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        sum+=ar[i];
    }

    int maxin = 0;
    for(int i=0;i<N;i++)
    {
        cin>>br[i];
        sum+=br[i];
        if(br[i] > br[maxin])maxin = i;
    }

    cout<<sum-br[maxin]<<endl;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
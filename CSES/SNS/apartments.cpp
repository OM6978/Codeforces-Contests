#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,M,K;
    cin>>N>>M>>K;

    vector<int> ar(N),br(M);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    for(int i=0;i<M;i++)
    {
        cin>>br[i];
    }

    sort(ar.begin(),ar.end());
    sort(br.begin(),br.end());

    int i=0,j=0,ans=0;
    while(i<N && j<M)
    {
        if(abs(br[j] - ar[i]) <= K)
        {
            j++;
            i++;
            ans++;
        }
        else
        {
            if(br[j] > ar[i])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }

    cout << ans << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();

    return 0;
}
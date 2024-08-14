#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,Q;
    cin>>N>>Q;

    string a,b;
    cin>>a>>b;

    int pref[26][2][N];
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<N;j++)
        {
            pref[i][0][j] = 0;
            pref[i][1][j] = 0;
        }
    }

    pref[a[0] - 'a'][0][0]++;
    pref[b[0] - 'a'][1][0]++;

    for(int i=1;i<N;i++)
    {
        for(int j=0;j<26;j++)
        {
            pref[j][0][i] = pref[j][0][i-1];
            pref[j][1][i] = pref[j][1][i-1];
        }
        pref[a[i] - 'a'][0][i]++;
        pref[b[i] - 'a'][1][i]++;
    }

    int l,r;
    for(int i=0;i<Q;i++)
    {
        cin>>l>>r;
        l--,r--;

        int ans=0;
        for(int j=0;j<26;j++)
        {
            ans+= abs((pref[j][0][r] - (l!=0)*pref[j][0][l-1]) - (pref[j][1][r] - (l!=0)*pref[j][1][l-1]));
        }

        cout<<ans/2<<'\n';
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
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;

    int freqz[2] = {0};
    for(char a: s)
    {
        int ax = a-'A';
        freqz[ax]++;
    }

    if((freqz[0]&1) || (freqz[1]&1)){cout<<"NO"<<'\n';return;}

    int q2_qz[2] = {0};
    for(int i=0;i<s.size()/2;i++)
    {
        int ax = s[i] - 'A';
        q2_qz[ax]++;
    }

    int l=0,r=(freqz[0]+freqz[1])/2;
    while(1)
    {
        if(q2_qz[0]*2 == freqz[0] && q2_qz[1]*2 == freqz[1])
        {
            cout<<"YES"<<'\n';
            cout<<l+1<<' '<<r+1<<'\n';
            return;
        }

        if(r==s.size())break;

        q2_qz[s[l++] - 'A']--;
        q2_qz[s[r++] - 'A']++;
    }

    cout<<"NO"<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}
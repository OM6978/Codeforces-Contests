#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9 + 7;

void solve()
{
    string s;
    cin>>s;

    map<int,vector<int>> m1;

    int sum = 0,N = s.size();
    for(int i=0;i<N;i++)
    {
        sum+= (s[i] == '1') - (s[i] == '0');
        m1[sum].push_back(i);
    }

    int ans = 0,curr = 0;
    for(int i=0;i<N;i++)
    {
        int nums = m1[curr].end() - lower_bound(m1[curr].begin(),m1[curr].end(),i);
        ans+= (nums*(nums - 1))/2;

        curr+= (s[i] == '1') - (s[i] == '0');
    }

    cout << ans <<'\n';
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
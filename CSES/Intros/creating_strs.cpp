#include <bits/stdc++.h>
using namespace std;

void makeperms(int i,string & curr,string & s,vector<string> & ans)
{
    if(i==s.size())
    {
        ans.push_back(curr);
        return;
    }

    curr.push_back(s[i]);
    makeperms(i+1,curr,s,ans);

    int j = curr.size()-1;
    while(j>0)
    {
        swap(curr[j-1],curr[j]);
        makeperms(i+1,curr,s,ans);
        j--;
    }
    curr.erase(curr.begin());
}

void solve()
{
    string s;
    cin>>s;

    string curr;
    vector<string> ans;

    makeperms(0,curr,s,ans);

    sort(ans.begin(),ans.end());

    vector<string> res;

    res.push_back(ans[0]);
    for(int i=1;i<ans.size();i++)
    {
        if(ans[i] != ans[i-1])
        {
            res.push_back(ans[i]);
        }
    }

    cout << res.size() << '\n';

    for(int i=0;i<res.size();i++)
    {
        cout << res[i] << '\n';
    }
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
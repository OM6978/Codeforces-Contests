#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,K;
    cin>>N>>K;

    int freqz[14];
    for(int i=0;i<14;i++)freqz[i] = 0;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        freqz[ar[i]]++;
    }

    vector<int> nums;
    for(int i=1;i<=13;i++)
    {
        if(freqz[i]!=0)nums.push_back(freqz[i]);
    }

    sort(nums.begin(),nums.end(),greater<int>());

    int days = 0,vis[nums.size()];
    for(int i=0;i<nums.size();i++)vis[i] = 0;

    for(int i=0;i<nums.size();i++)
    {
        if(vis[i])continue;

        vis[i] = 1;
        days++;
        int sum = nums[i];
        for(int j = i+1;j<nums.size();j++)
        {
            if(vis[j])continue;
            
            if(sum + nums[j] <= K)
            {
                sum+=nums[j];
                vis[j]=1;
            }
        }
    }

    cout << days << '\n';
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
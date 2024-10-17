#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    for(int i=0;i<N;i++)cin>>ar[i];

    vector<pair<int,int>> s1;

    s1.push_back({0,0});
    s1.push_back({ar[0],1});

    for(int i=1;i<N;i++)
    {
        int prev_last = s1[s1.size()-2].first,last = s1.back().first;

        if(ar[i] > last)s1.push_back({ar[i],1});
        else if(ar[i] == last)(--s1.end())->second++;
        else
        {
            int cnt = s1.back().second;
            if((last - prev_last)*cnt + ar[i] >= prev_last)
            {
                int y = (last*cnt + ar[i])/(1+cnt);
                int rem = (last*cnt + ar[i])%(1+cnt);

                s1[s1.size()-1].first = y;
                s1[s1.size()-1].second = cnt - rem + 1;
                if(rem !=0)s1.push_back({y+1,rem});
            }
            else
            {
                s1.pop_back();
                s1[s1.size()-1].second+=cnt;
                ar[i--]+= (last - prev_last)*cnt;
            }
        }
    }

    cout << s1.back().first - s1[1].first << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
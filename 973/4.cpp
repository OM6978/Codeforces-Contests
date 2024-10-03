#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    vector<pair<int,int>> s1;

    int last = ar[0];
    for(int i=1;i<N;i++)
    {
        if(ar[i] > last)
        {
            last = s1.back().first;
            s1.push_back({ar[i],1});
        }
        else if(ar[i] == last)
        {
            auto curr = s1.back();
            curr.second++;
            s1.push_back(curr);
        }
        else
        {
            int num = s1.back().first,cnt = s1.back().second;
            if((num - last)*cnt + ar[i] >= last)
            {

            }
            else
            {
                ar[i]+= (num - last)*cnt;
                s1.pop_back();
                s1.back()
            }
        }
    }

    cout << s1.back().first - s1[0].first << '\n';
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
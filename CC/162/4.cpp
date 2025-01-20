#include <bits/stdc++.h>
using namespace std;

int convemp(vector<int> & cnts)
{
    int M = cnts.size();

    multiset<pair<int,int>> ms;
    set<int> inds;
    for(int i=0;i<M;i++)ms.insert({cnts[i],i}),inds.insert(i);

    int most = (*(--ms.end())).first;
    while(ms.size()>2)
    {
        auto [elem,in] = *ms.begin();
        most = max(most,elem);

        ms.erase(ms.begin());

        auto it = inds.find(in);
        if(it == inds.begin() || it == --inds.end())
        {
            inds.erase(in);
            continue;
        }

        int low = *(--it),high = *(++++it);
        inds.erase(in);

        ms.erase({cnts[low],low});
        cnts[low] = cnts[low] + cnts[high] - elem;
        ms.insert({cnts[low],low});

        ms.erase({cnts[high],high});
        inds.erase(high);
    }
    
    if(ms.size())
    {
        most = max(most,(*(--ms.end())).first);
    }

    return most;
}

void solve()
{
    int N;
    cin>>N;

    string s;
    cin>>s;
    s.push_back('0');

    int last = 0,count = 0;
    vector<int> cnts;
    for(char x : s)
    {
        if(x == last)count++;
        else
        {
            last = x;
            cnts.push_back(count);
            count = 1;
        }
    }

    cnts.erase(cnts.begin());

    cout << convemp(cnts) << '\n';
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
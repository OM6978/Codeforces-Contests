#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    int A[N+1],B[N+1];
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)cin>>B[i];

    int possA[N+1],possB[N+1];
    for(int i=1;i<=N;i++)
    {
        possA[A[i]] = i;
        possB[B[i]] = i;
    }

    vector<pair<int,int>> ans;

    for(int i=1;i<=N;i++)
    {
        int req = possB[i],curr = possA[i];

        if(req == curr)continue;
        else if(req > curr)
        {
            if(A[req] > A[curr]){cout << -1 << '\n';return;}

            vector<pair<int,int>> smaller;
            for(int i=curr+1;i<=req;i++)if(A[i] < A[curr])smaller.push_back({A[i],i});

            sort(smaller.begin(),smaller.end());    

            int lastpos = -1;
            for(int i=smaller.size()-1;i>=0 && curr!=req;i++)
            {
                int currpos = smaller[i].second,a = smaller[i].first;
                if(currpos < lastpos)continue;

                ans.push_back({curr,possA[a]});
                swap(possA[a],possA[A[curr]]);
                swap(A[currpos],A[curr]);

                lastpos = currpos;
                curr = currpos;
            }
        }
        else
        {
            if(A[req] < A[curr]){cout << -1 << '\n';return;}

            vector<pair<int,int>> bigger;
            for(int i=curr-1;i>=req;i--)if(A[i] > A[curr])bigger.push_back({A[i],i});

            sort(bigger.begin(),bigger.end());

            int lastpos = curr+1;
            for(int i=0;i<bigger.size() && curr!=req;i++)
            {
                int currpos = bigger[i].second,a = bigger[i].first;
                if(currpos > lastpos)continue;

                ans.push_back({currpos,curr});

                swap(possA[a],possA[A[curr]]);
                swap(A[currpos],A[curr]);

                lastpos = currpos;
                curr = currpos;
            }
        }
    }

    cout << ans.size() << '\n';
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
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
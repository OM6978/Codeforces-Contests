#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,K;
    cin>>N>>K;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    vector<int> sar = ar;
    sort(sar.begin(),sar.end());
    set<int> topK(sar.begin(),sar.begin()+K-1);

    vector<int> br;
    for(int i=0;i<N;i++)
    {
        if(topK.find(ar[i])!=topK.end())
        {
            br.push_back(ar[i]);
        }
    }

    int last;
    if(K!=1)
        last = sar[K-2];

    int leeway = br.size() - (K-1);
    int l=0,r = br.size() - 1;
    while(l<r)
    {
        if(br[l] != br[r])
        {
            leeway--;
            if(leeway < 0 || (br[l] != last && br[r] != last))
            {
                cout << "NO\n";
                return;
            }

            if(br[l] < br[r])
            {
                r--;
            }
            else l++;
        }
        else
        {
            l++;
            r--;
        }
    }

    cout << "YES\n";
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
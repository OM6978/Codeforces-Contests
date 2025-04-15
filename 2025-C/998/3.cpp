#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,K;
    cin>>N>>K;

    map<int,int> freq;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        freq[ar[i]]++;
    }

    int posits = 0,negs = 0;
    for(int i=0;i<K/2 + 1;i++)
    {
        if(i == K - i)
        {
            int val = freq[i];
            posits+= val/2;
            negs += (val&1);
        }
        else
        {
            posits += min(freq[i],freq[K - i]);
            negs += max(freq[i],freq[K - i]) - min(freq[i],freq[K - i]);
        }
    }

    int subs = (negs+1)/2;
    cout << max(min(posits,N/2 - subs),0) << '\n';
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
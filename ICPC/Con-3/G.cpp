#include <bits/stdc++.h>
using namespace std;

bool good(int rounds,string & s,vector<int> & poss)
{
    int M = poss.size(),N = s.size();

    int last = -1;
    for(int i=0;i<M;i++)
    {
        int a = poss[i];
        int comp = a - last - 1;
        if(comp > rounds)return false;

        last = a + rounds - (comp == rounds && rounds != 0);
    }

    return (last < N-1)?false:true;
}

void solve()
{
    int N;
    cin>>N;

    string s;
    cin>>s;

    vector<int> poss;
    for(int i=0;i<N;i++)
    {
        if(s[i] == '1')
        poss.push_back(i);
    }

    int l =-1,r = N;
    while(l+1<r)
    {
        int mid = (l+r)/2;
        if(good(mid,s,poss))r = mid;
        else l = mid;
    }

    cout << r << '\n';
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
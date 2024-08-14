#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

int findindex(int x,int* r,int K)
{
    return lower_bound(r,r+K,x)-r;
}

void reversestring(string &s,int* a,int* b)
{
    a--;b--;
    
}

void solve()
{
    int N,K;
    cin>>N>>K;

    string s;
    cin>>s;
    int l[K],r[K];
    for(int i=0;i<K;i++)cin>>l[i];
    for(int i=0;i<K;i++)cin>>r[i];

    int q;
    cin>>q;

    int a[q],b[q];
    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        int index=findindex(x,r,K);
        a[i]=min(x,r[index]+l[index]- x),b[i]=max(x,r[index]+l[index]- x);
    }

    reversestring(s,a,b);

    cout<<s<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
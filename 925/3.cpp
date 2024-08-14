#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int N;
    cin>>N;
    int ar[N],l=1,r=1,currl,currr;

    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    currl = ar[0];
    for(int i=1;i<N;i++)
    {
        if(ar[i]==currl)l++;
        else break;
    }

    currr = ar[N-1];
    for(int i=N-2;i>=0;i--)
    {
        if(ar[i]==currr)r++;
        else break;
    }

    if(l == N)cout<<0<<endl;
    else if(currl == currr)cout<< N- l - r<<endl;
    else cout<< N - max(l,r)<<endl;
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
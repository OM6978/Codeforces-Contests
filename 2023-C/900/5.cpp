#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

int findr(int* a,int l,int K,int N)
{
    int ret=l,sum=a[l];
    if(K>a[l])return -1;
    for(int i=l+1;i<N;i++)
    {
        if((sum&a[i])>=K){ret++;sum=sum&a[i];}
        else break;
    }
    return ret+1;
}

void solve()
{
    int N;
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++)cin>>a[i];

    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int l,K;
        cin>>l>>K;

        int temp=findr(a,l-1,K,N);
        cout<<temp<<space;
    }
    cout<<endl;
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
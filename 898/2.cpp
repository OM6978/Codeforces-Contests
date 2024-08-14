#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int pair<int>

void solve()
{
    int N;
    cin>>N;
    int startarr[N],min=INT32_MAX,product=1,used=0;
    for(int i=0;i<N;i++)
    {
        cin>>startarr[i];
        if(startarr[i]==0&&used==0){startarr[i]=1;used=1;}
        product*=startarr[i];
        if(startarr[i]<min)min=startarr[i];
    }

    if(used==0)
    {
        product=(product/min)*(min+1);
    }

    cout<<product<<endl;

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
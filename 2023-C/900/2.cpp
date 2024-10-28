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

    int output[N];
    output[0]=1;output[1]=3;
    int i=2,num=4;
    while(1)
    {
        if((num + output[i-1])%3==0||(num%(output[i-1] + output[i-2]))==0)num++;
        else output[i++]=num++;
        if(i==N)break;
    }
    for(int i=0;i<N;i++)
    {
        cout<<output[i]<<space;
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
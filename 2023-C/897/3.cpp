#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'

void solve()
{
    int N;
    cin>>N;
    int startarr[N];
    for(int i=0;i<N;i++)
    {
        cin>>startarr[i];
    }
    sort(startarr,startarr + N);

    int highest=0;
    for(int i=0;i<N;i++)
    {
        if(startarr[i]!=highest)break;
        highest++;
    }
    
    int input,output=highest;
    cout<<output<<endl;
    cin>>input;
    while(input!=-1)
    {
        output=input;
        cout<<output<<endl;
        cin>>input;
        if(input==-2)assert(0);
    }
}

signed main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
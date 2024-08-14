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

    int fir=0,done1=0,sec=0,done2=0;
    string temp;
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        for(int j=0;j<N;j++)
        {
            if(done1==0 && temp[j]=='1')fir++;
            else if(done2==0 && temp[j]=='1')sec++;
        }
        if(fir!=0)done1=1;
        if(sec!=0)done2=1;
    }

    // cout<<fir<<space<<sec<<endl;
    if(fir==sec)cout<<"SQUARE"<<endl;
    else cout<<"TRIANGLE"<<endl;
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
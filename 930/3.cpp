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

    int indexmax = 0;
    v_int ORmax;
    char temp;

    for(int i=1;i<N;i++) //find max
    {
        cout<<'?'<<space<<i<<space<<i<<space<<indexmax<<space<<indexmax<<endl;

        cin>>temp;

        if(temp=='>')indexmax=i;
    }

    int ORlol=0;
    for(int i=0;i<N;i++) //find OR max
    {
        cout<<'?'<<space<<indexmax<<space<<i<<space<<indexmax<<space<<ORlol<<endl;
        
        cin>>temp;

        if(temp=='>')
        {
            ORlol=i;
            ORmax.clear();
            ORmax.push_back(i);
        }
        else if(temp == '=')ORmax.push_back(i);
    }

    int ORsize = ORmax.size(),ans=ORmax[0];
    for(int i=1;i<ORsize;i++)   //find the smallest ORmax
    {
        cout<<'?'<<space<<ans<<space<<ans<<space<<ORmax[i]<<space<<ORmax[i]<<endl;

        cin>>temp;
        if(temp == '>')ans=ORmax[i];
    }

    cout<<'!'<<space<<indexmax<<space<<ans<<endl;
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
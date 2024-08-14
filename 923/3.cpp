#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    unordered_map<int,int> m1,m2;
    int x,y,k;
    cin>>x>>y>>k;

    int arr1[x],arr2[y],*un1,*un2;
    for(int i=0;i<x;i++)
    {
        cin>>arr1[i];
        m1[arr1[i]]++;
    }

    for(int i=0;i<y;i++)
    {
        cin>>arr2[i];
        m2[arr2[i]]++;
    }

    int one=0,two=0,both=0;
    for(int i=1;i<=k;i++)
    {
        if(m1[i]>0&&m2[i]>0)both++;
        else if(m1[i]>0)one++;
        else if(m2[i]>0)two++;
        else{cout<<"NO"<<endl;return;}
    }

    if(min(one,two) + both >=k/2 && max(one,two) + both - k/2 + min(one,two) >= k/2)
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
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
#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    string arr;
    cin>>arr;
    int count=0,lastB=-1;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]=='A')count++;
        if(arr[i]=='B')lastB=i;
    }
    count=count-(arr.size()-1-lastB);

    cout<<count<<endl;
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
#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int N,m;
    cin>>N>>m;
    v_int ar(N);
    int prod=1;

    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        prod*=ar[i];
    }

    string s;
    cin>>s;

    v_int temp;

    for(int i=0;i<N;i++)
    {
        char command = s[i];
        if(command=='L')
        {
            temp.push_back(*ar.begin());
            ar.erase(ar.begin());
        }
        else
        {
            temp.push_back(ar.back());
            ar.pop_back();
        }
    }
    temp.resize(N);

    prod=1;
    v_int ans;
    for(int i=N-1;i>=0;i--)
    {
        prod*=temp[i];
        prod%=m;
        ans.push_back(prod);
    }
    ans.resize(N);

    for(int i=N-1;i>=0;i--)cout<<ans[i]<<space;
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
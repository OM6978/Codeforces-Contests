#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int N,K;
    cin>>N;
    vector<int> arr[N];
    unordered_map<int,int> mapp;
    int totelems=0,max=-1;
    for(int i=0;i<N;i++)
    {
        int temp;
        cin>>K;
        for(int j=0;j<K;j++)
        {
            cin>>temp;arr[i].push_back(temp);
            mapp[temp]++;
            if(mapp[temp]==1)totelems++;
        }
    }

    int current=totelems;
    unordered_map<int,int> currentcount;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            currentcount[arr[i][j]]++;
            if(mapp[arr[i][j]]==currentcount[arr[i][j]])current--;
        }
        if(current!=totelems&&current>max)max=current;
        current=totelems;
        currentcount.clear();
    }

    cout<<max<<endl;
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
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
    int arr[N];
    for(int i=0;i<N;i++)cin>>arr[i];
    int descends=arr[0],Lasteq=0;
    vector<pair<int,int>> DESS;

    for(int i=1;i<N;i++)
    {
        if(arr[i]>arr[i-1])
        {
            descends+=arr[i]-arr[i-1];
            pair<int,int> temp;
            temp.first = i;
            temp.second = arr[i]-arr[i-1];
            DESS.push_back(temp);
            Lasteq=i;
        }
        else if(arr[i]==arr[i-1])
        {
            if(Lasteq==0||arr[Lasteq]-arr[Lasteq-1]!=1){cout<<"NO"<<endl;return;}
        }
        else if(arr[i]-arr[i-1]==-1)
        {
            descends--;
            DESS.back().second--;
            if(DESS.back().second==0)DESS.pop_back();
            
            Lasteq=i;
        }
        else cout<<"NO"<<endl;return;
    }

    if(descends!=0)
    {
        for(int i=DESS.size()-1;i>=0;i--)
        {
            if(arr[DESS[i].first]-arr[DESS[i].first-1]==1)
            descends--;
            DESS.pop_back();
        }
        if(descends==0)cout<<"YES"<<endl;
        else cout<<"NO";
    }
    else cout<<"YES";
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
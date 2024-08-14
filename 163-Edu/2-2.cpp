#include <bits/stdc++.h>
using namespace std;

#define sce " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int N;
    cin>>N;

    int arr[N],flag=0;
    v_int ans;
    ans.push_back(-1);

    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
        int first = arr[i]/10,sec = arr[i]%10;

        if(first!=0 && sec>=first && first>=ans.back() && flag == 0)
        {
            ans.push_back(first);
            ans.push_back(sec);
        }
        else if(first*10 + sec >= ans.back() && flag == 0)
        {
            ans.push_back(first*10 + sec);
        }
        else flag=1;
    }

    if(flag)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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
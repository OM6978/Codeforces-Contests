#include <bits/stdc++.h>
using namespace std;

#define sce " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

int fuckthis(int lol,int prev)
{
    v_int digitsc;
    while(lol!=0)
    {
        digitsc.insert(digitsc.begin(),lol%10);
        lol/=10;
    }
    digitsc.insert(digitsc.begin(),prev);

    for(int i=1;i<digitsc.size();i++)
    {
        if(digitsc[i]<digitsc[i-1])return 0;
    }

    return 1;
}

void solve()
{
    int N;
    cin>>N;

    int arr[N],yes=0,flag=0;
    v_int ans,digitsc;

    cin>>arr[0];

    if(arr[0]!=0 && fuckthis(arr[0],-1))
    {
        int temp=arr[0];

        while(temp!=0)
        {
            int lol = temp%10;
            digitsc.insert(digitsc.begin(),lol);
            temp/=10;
        }
        ans.insert(ans.end(),digitsc.begin(),digitsc.end());
        digitsc.clear();
    }
    else
    {
        ans.push_back(arr[0]);
        if(arr[0]!=0)yes=1;
    }

    for(int i=1;i<N;i++)
    {
        cin>>arr[i];

        if(arr[i]!=0 && (yes==0) && fuckthis(arr[i],ans.back()) && flag==0)
        {
            int temp=arr[i];

            while(temp!=0)
            {
                int lol = temp%10;
                digitsc.insert(digitsc.begin(),lol);
                temp/=10;
            }
            ans.insert(ans.end(),digitsc.begin(),digitsc.end());
            digitsc.clear();
        }
        else if(arr[i]<ans.back() && flag == 0)
        {
            flag=1;
        }
        else if(flag==0)
        {
            ans.push_back(arr[i]);
            if(arr[0]!=0)yes=1;
        }
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
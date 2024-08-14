#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>


unordered_map <int,int> prmap;

void mapfacs(int n) 
{ 
    while (n % 2 == 0) 
    { 
        prmap[2]++;
        n = n/2; 
    } 
    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        while (n % i == 0) 
        { 
            prmap[i]++;
            n = n/i; 
        } 
    } 
 
    if (n > 2) 
        prmap[n]++;
}

void solve()
{
    int N;
    cin>>N;

    int nums[N];
    for(int i=0;i<N;i++){cin>>nums[i];mapfacs(nums[i]);}

    for (auto &&p : prmap)
    {
        if(p.second%N!=0){cout<<"NO"<<endl;prmap.clear();return;}
    }
    
    cout<<"YES"<<endl;

    prmap.clear();
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
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
    v_int s1,s2;
    int ascends=0,temp;
    s1.push_back(N+1);
    s2.push_back(N+1);

    for(int i=0;i<N;i++)
    {
        cin>>temp;
        if(temp<=s1[s1.size()-1])s1.push_back(temp);
        else if(temp<=s2[s2.size()-1])s2.push_back(temp);
        else
        {
            ascends++;
            s1.push_back(s2[s2.size()-1]);
            s2.push_back(temp);
        }
    }

    cout<<ascends<<endl;
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
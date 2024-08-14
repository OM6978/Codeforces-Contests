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
    string why[2];
    cin>>why[0];
    cin>>why[1];

    int ar[2][N];
    for(int i=0;i<N;i++)ar[0][i] = (int)why[0][i] - 48;
    for(int i=0;i<N;i++)ar[1][i] = (int)why[1][i] - 48;

    v_int s;
    int flag=0,first=-1;

    s.push_back(ar[0][0]);
    if(ar[1][0]<ar[0][1]){s.push_back(ar[1][0]);flag=1;first=0;}

    for(int i=1;i<N;i++)
    {
        if(flag==1)s.push_back(ar[1][i]);
        else
        {
            if(ar[1][i-1]<ar[0][i])
            {
                flag=1;
                first=i-1;
                s.push_back(ar[1][i-1]);
                i--;
            }
            else
            {
                s.push_back(ar[0][i]);
            }
        }
    }
    
    if(flag==0){s.push_back(ar[1][N-1]);first=N-1;}

    int ways=1;
    for(int i = first-1;i>=0;i--)
    {
        if(ar[0][i+1]==ar[1][i])ways++;
        else break;
    }

    for(int i=0;i<s.size();i++)cout<<s[i];
    cout<<endl;
    cout<<ways<<endl;
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
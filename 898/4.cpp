#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int pair<int>

void solve()
{
    int N,K,steps=0;
    cin>>N>>K;
    char input[N];
    for(int i=0;i<N;i++)
    {
        cin>>input[i];
    }

    for(int i=0;i<N;i++)
    {
        if(input[i]=='B')
        {
            i+=K-1;
            steps++;
        }
    }

    cout<<steps<<endl;
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
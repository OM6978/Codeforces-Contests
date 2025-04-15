#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int pair<int>

void solve()
{
    unordered_map<int,int> camps;
    int N,M;
    cin>>N>>M;
    int A,B,D,zeroth;

    for(int i=0;i<M;i++)
    {
        cin>>A>>B>>D;
        if(D==0)
        {
            cout<<"NO"<<endl;
            return;
        }
        if(i==0)
        {
            camps[B]=0;
            zeroth=B;
            camps[A]=camps[B]+ D;
        }
        else
        {
            if((camps[B]==0&&B!=zeroth))
            {
                camps[B]=D-camps[A];
            }
            else if(camps[A]==0&&A!=zeroth)
            {
                camps[A]=camps[B]+D;
            }
            else if(camps[A]-camps[B]!=D)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
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
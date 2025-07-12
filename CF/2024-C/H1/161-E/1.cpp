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
    string a,b,c;
    cin>>a>>b>>c;

    char A,B,C;
    for(int i=0;i<N;i++)
    {
        A=a[i],B=b[i],C=c[i];
        if(A==B&&A!=C){cout<<"YES"<<endl;return;}
        else if(A!=B && B!=C && C!=A){cout<<"YES"<<endl;return;}
    }
    cout<<"NO"<<endl;
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
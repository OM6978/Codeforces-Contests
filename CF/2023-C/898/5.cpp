#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int pair<int>

void solve()
{
    int N,X;
    cin>>N>>X;
    int startarr[N];
    for(int i=0;i<N;i++)
    {
        cin>>startarr[i];
    }
    sort(startarr, startarr + N);

    int prev=startarr[0],output=0,H=startarr[0];
    for(int i=1;i<N;i++)
    {
        output+=(startarr[i]-prev)*i;
        H+=startarr[i]-prev;
        if(output>X)
        {
            output-=(startarr[i]-prev)*i;
            H-=startarr[i]-prev;
            int temp=(X-output)/i;
            H+=temp;
            output+=temp*i;
            break;
        }
        prev=startarr[i];
    }
    H+=(X-output)/N;

    cout<<H<<endl;
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
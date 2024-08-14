#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int N;
    cin>>N;

    string s;
    cin>>s;

    int satl=0,satr=0;
    for(int i=0;i<N;i++)if(s[i]=='1')satr++;

    v_int suitable;
    for(int i=0;i<N;i++)
    {
        if(satr>=((N-i)/2 + ((N-i)&1)) && satl >= ((i/2) + (i&1)))suitable.push_back(i);
        
        if(s[i]=='0')satl++;
        else satr--;
    }

    if(satl >= (N/2) + (N&1))suitable.push_back(N);

    int best = suitable[0];
    int distans=min(abs(N/2 - suitable[0]),abs(N/2 + (N&1) - suitable[0]));
    int distlol;

    for(int i=1;i<suitable.size();i++)
    {
        distlol = min(abs(N/2 - suitable[i]),abs(N/2 + (N&1) - suitable[i]));
        if(distlol<distans){best=suitable[i];distans=distlol;}
    }

    cout<<best<<endl;
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
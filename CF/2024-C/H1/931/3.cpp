#include <bits/stdc++.h>
using namespace std;

#define sce " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void ask(int x,int y){cout<<'?'<<sce<<x<<sce<<y<<endl;}
void print(int x,int y){cout<<'!'<<sce<<x<<sce<<y<<endl;}

void solve()
{
    int N,M,dist;
    cin>>N>>M;

    ask(1,1);
    cin>>dist;

    int dist1,dist2;
    int x1=min(dist+1,N);
    int x2=(dist+1>M)*(dist+2 - M) + (dist+1<=M);
    int y2=min(dist+1,M);
    int y1=(dist+1>N)*(dist+2 - N) + (dist+1<=N);

    ask(x1,y1);
    cin>>dist1;

    ask(x2,y2);
    cin>>dist2;

    if(dist1+dist2!= abs(x1-x2) + abs(y1 - y2) && ((dist1&1)==0) && ((dist2&1)==0))
    {
        ask(x1-dist1/2,y1+dist1/2);

        int lol;
        cin>>lol;
        
        if(lol==0)print(x1-dist1/2,y1+dist1/2);
        else print(x2+dist2/2,y2-dist2/2);
    }
    else if((dist2&1)==1){print(x1-dist1/2,y1+dist1/2);}
    else print(x2+dist2/2,y2-dist2/2);
}

signed main()
{    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
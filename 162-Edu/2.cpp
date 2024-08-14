#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

v_int neg,pos,hneg,hpos;

int shoot(int N, int K)
{
    int inc=0,down=0;

    while(1)
    {
        int bullets = K;
        while(bullets!=0)
        {
            if(pos[0]>=abs(neg[0]))
            {
                if(hpos[0]>K){bullets=0;hpos[0]-=K;}
                else if(hpos[0]==K)
                {
                    bullets=0;
                    pos.erase(pos.begin());
                    hpos.erase(hpos.begin());
                    down++;
                }
                else
                {
                    bullets-=hpos[0];
                    pos.erase(pos.begin());
                    hpos.erase(hpos.begin());
                    down++;
                }
            }
            else
            {
                if(hneg[0]>K){bullets=0;hneg[0]-=K;}
                else if(hneg[0]==K)
                {
                    bullets=0;
                    neg.erase(neg.begin());
                    hneg.erase(hneg.begin());
                    down++;
                }
                else
                {
                    bullets-=hpos[0];
                    neg.erase(neg.begin());
                    hneg.erase(hneg.begin());
                    down++;
                }         
            }
            if(down == N)return 1;
        }
        inc++;
        if(pos[0]-inc==0 || abs(neg[0])-inc==0)return 0;
    }
}

void solve()
{
    int N,K;
    cin>>N>>K;

    int temp[N],h[N];
    for(int i=0;i<N;i++)
    {
        cin>>temp[i];
        h[i]=(temp[i]);
    }

    for(int i=0;i<N;i++)
    {
        cin>>temp[i];
        if(temp[i]<0)neg.push_back(temp[i]);
        else pos.push_back(temp[i]);
    }

    for(int i=0;i<N;i++)
    {
        if(temp[i]<0)hneg.push_back(h[i]);
        else hpos.push_back(h[i]);
    }

    reverse(hneg.begin(),hneg.end());
    reverse(neg.begin(),neg.end());

    int ans = shoot(N,K);
    if(ans==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
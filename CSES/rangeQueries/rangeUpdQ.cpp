#include <bits/stdc++.h>
using namespace std;

#define int long long

const int nullval = 0;
int getOp(int x,int y){return x+y;}

int getSTOp(vector<int> & st,int l,int r,int x,int lx,int rx)
{
    if(lx >= r || rx <= l)return nullval;
    if(lx >= l && rx <= r)return st[x];

    int mid = (lx+rx)>>1;
    int res1 = getSTOp(st,l,r,2*x+1,lx,mid);
    int res2 = getSTOp(st,l,r,2*x+2,mid,rx);
    return getOp(res1,res2);
}

int getSTWrapper(vector<int> & st,int l,int r)
{
    return getSTOp(st,l,r,0,0,(st.size()+1)/2);
}

int getIn(vector<int> & st,int i,int lx,int rx,int x)
{
    if(lx > i || rx <= i)return -1;
    if(lx + 1 >= rx)return x;

    int mid = (lx+rx)>>1;
    int in1 = getIn(st,i,lx,mid,2*x+1);
    int in2 = getIn(st,i,mid,rx,2*x+2);
    if(in1!=-1)return in1;
    else return in2;
}

int getInWrapper(vector<int> & st,int i)
{
    return getIn(st,i,0,(st.size()+1)/2,0);
}

void setSTVal(vector<int> & st,int l,int r,int x,int lx,int rx,int val)
{
    if(rx <= l || lx >= r)return;
    if(lx + 1 < rx)
    {
        int mid = (lx + rx)>>1;
        setSTVal(st,l,r,2*x+1,lx,mid,val);
        setSTVal(st,l,r,2*x+2,mid,rx,val);

        st[x] = getOp(st[2*x+1],st[2*x+2]);
    }
    else st[x] = val;
}

void setSTWrapper(vector<int> & st,int i,int val)
{
    setSTVal(st,i,i+1,0,0,(st.size()+1)/2,val);
}

vector<int> initST(vector<int> & ar)
{
    int N = ar.size();
    int sz = 1;
    while(sz<N)sz<<=1;

    vector<int> st(2*sz-1,nullval);
    for(int i=0;i<N;i++)
        setSTWrapper(st,i,ar[i]);

    return st;
}

void solve()
{
    int N,Q;
    cin>>N>>Q;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    vector<int> lz(N,0);
    vector<int> st = initST(lz);

    while(Q--)
    {
        int op;
        cin>>op;

        if(op == 1)
        {
            int a,b,u;
            cin>>a>>b>>u;

            int in1 = getInWrapper(st,a-1);
            int in2 = getInWrapper(st,b);
            int val1 = st[in1] + u;
            int val2 = st[in2] - u;

            setSTWrapper(st,a-1,val1);
            setSTWrapper(st,b,val2);
        }
        else
        {
            int pos;
            cin>>pos;

            cout << getSTWrapper(st,0,pos) + ar[pos-1] << '\n';
        }
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();

    return 0;
}
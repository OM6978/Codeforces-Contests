#include <bits/stdc++.h>
using namespace std;

const int halo = 1e9;

int operation(int a,int b){return min(a,b);}

int getMid(int s, int e){return s + (e -s)/2;} 

int getopUtil(vector<int> & st, int ss, int se, int qs, int qe, int si)
{
    if (se < qs || ss > qe)
        return halo; 

    if(qs <= ss && qe >= se)
        return st[si];

    int mid = getMid(ss, se);
    return operation(getopUtil(st, ss, mid, qs, qe, 2*si+1),getopUtil(st, mid+1, se, qs, qe, 2*si+2)); 
}

int getop(vector<int> & st, int n, int qs, int qe) 
{
    return getopUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(vector<int> & arr, int ss, int se, vector<int> & st, int si) 
{
    if (ss==se) 
    {
        st[si] = arr[ss]; 
        return arr[ss];
    }

    int mid = getMid(ss, se); 
    st[si] = operation(constructSTUtil(arr, ss, mid, st, si*2+1),constructSTUtil(arr, mid+1, se, st, si*2+2));

    return st[si]; 
} 

vector<int> constructST(vector<int> & arr, int n) 
{
    int x = (int)(ceil(log2(n))); 
    int max_size = 2*(int)pow(2, x) - 1; 
    vector<int> st(max_size,halo);

    constructSTUtil(arr, 0, n-1, st, 0);
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

    vector<int> st = constructST(ar,N);

    while(Q--)
    {
        int l,r;
        cin>>l>>r;

        cout << getop(st,N,l-1,r-1) << '\n';
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
#include <bits/stdc++.h>
using namespace std;

int operation(int a,int b){return a^b;}

int getMid(int s, int e){return s + (e -s)/2;} 

int getopUtil(int *st, int ss, int se, int qs, int qe, int si) 
{
    if (se < qs || ss > qe)
        return 0; 

    if(qs <= ss && qe >= se)
        return st[si];

    int mid = getMid(ss, se);
    return operation(getopUtil(st, ss, mid, qs, qe, 2*si+1),getopUtil(st, mid+1, se, qs, qe, 2*si+2)); 
}

int getop(int *st, int n, int qs, int qe) 
{
    return getopUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si) 
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

int *constructST(int arr[], int n) 
{
    int x = (int)(ceil(log2(n))); 
    int max_size = 2*(int)pow(2, x) - 1; 
    int *st = new int[max_size]; 

    constructSTUtil(arr, 0, n-1, st, 0);
    return st; 
}

void solve()
{
    
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
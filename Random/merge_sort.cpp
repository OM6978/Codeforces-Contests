#include <bits/stdc++.h>
using namespace std;

void merge(int* ar1,int* ar2,int n1,int n2)
{
    int ar3[n1 + n2];
    int l1 = 0,l2 = 0;
    while(l1<n1 && l2<n2)
    {
        if(ar1[l1] <= ar2[l2])
        {
            ar3[l1+l2] = ar1[l1];
            l1++;
        }
        else
        {
            ar3[l1+l2] = ar2[l2];
            l2++;
        }
    }

    int* ar,l;
    if(l1==n1)ar = ar2,l = l2;
    else ar = ar1,l = l1;

    int ll = l1 + l2;
    while(ll < n1 + n2)
    {
        ar3[ll++] = ar[l++];
    }

    for(int i=0;i<n1;i++)
    {
        ar1[i] = ar3[i];
    }

    for(int i=n1;i<n1+n2;i++)
    {
        ar2[i-n1] = ar3[i];
    }
}

void merge_sort(int* ar,int N)
{
    if(N==1)return;

    int mid = N/2;
    merge_sort(ar,mid);
    merge_sort(&ar[mid],N - mid);

    merge(ar,&ar[mid],mid,N-mid);
}

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    merge_sort(ar,N);

    for(int i=0;i<N;i++)
    {
        cout << ar[i] << ' ';
    }
    cout << '\n';

    cout << (&ar[N/2])[0] << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
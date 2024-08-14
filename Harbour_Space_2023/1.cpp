#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int Test;
    scanf("%d",&Test);
    for(int l=0;l<Test;l++)
    {
    int x,y,n;
    cin>>x>>y>>n;

    int arr[n];
    arr[n-1]=y;
    arr[0]=x;
    for(int i=n-2,y=1;i>0;i--,y++)
    {
        arr[i]=arr[i+1]-y;
    }

    if(n>=3&&arr[1]-arr[0]<=arr[2]-arr[1])
    {
        cout<<-1<<"\n";
        continue;
    }

    for(int value : arr)
    {
        cout<<value<<" ";
    }
    cout<<"\n";
    }
    return 0;
}
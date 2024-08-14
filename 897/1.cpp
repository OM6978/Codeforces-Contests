#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    
    int Test;
    scanf("%d",&Test);
    for(int lol=0;lol<Test;lol++)
    {
    int N;
    cin>>N;

    int a[N],btemp[N],atemp[N],b[N];
    unordered_map<int,vector<int>> checker;


    for(int i=0;i<N;i++)
    {
        cin>>a[i];
        atemp[i]=a[i];
        btemp[i]=i+1;
    }

    sort(atemp,atemp+N);

    for(int i=0;i<N;i++)
    {
        checker[atemp[i]].push_back(btemp[N-i-1]);
    }

    for(int i=0;i<N;i++)
    {
        b[i]=checker[a[i]][0];
        checker[a[i]].erase(checker[a[i]].begin());
        cout<<b[i]<<space;
    }
    cout<<endl;
    }
    return 0;
}
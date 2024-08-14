#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'

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

    string binarystring;
    int binaryarray[N];

    cin>>binarystring;
    for(int i=0;i<N;i++)
    {
        binaryarray[i]=(int)binarystring[i]-48;
    }

    int notpalin=0;
    for(int i=0;i<N;i++)
    {
        if(binaryarray[i]!=binaryarray[N-i-1])
        {
            notpalin++;
        }
    }

    int min1s=notpalin/2;

    int output[N+1];
    for(int i=0;i<N+1;i++)
    {
        if(i>=min1s&&(N%2==1)&&i<=N-min1s)
        {
            output[i]=1;
        }
        else if(i>=min1s&&i<=N-min1s&&(N%2==0)&&((i-min1s)%2==0))
        {
            output[i]=1;
        }
        else
        {
            output[i]=0;
        }
    }

    for(int value:output)
    {
        cout<<value;
    }
    cout<<endl;
    }
    return 0;
}
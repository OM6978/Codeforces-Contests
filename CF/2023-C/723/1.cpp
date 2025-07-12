#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'

int prevneigh(int i,int N)
{
    if(i==0)return N-1;
    else return i-1;
}
int nextneigh(int i,int N)
{
    if(i==N-1)return 0;
    else return i+1;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    
    int Test;
    cin>>Test;
    while(Test--)
    {
    int N;
    cin>>N;
    N=2*N;
    int input[N];

    for(auto &value : input)
    {
        cin>>value;
    }
    sort(input,input + N);

    int output[N];
    for(int i=0;i<N/2;i++)
    {
        output[2*i]=input[i];
        output[2*i+1]=input[N-i-1];
    }

    for(auto &value : output)
    {
        cout<<value<<space;
    }
    cout<<endl;
    }
    return 0;
}
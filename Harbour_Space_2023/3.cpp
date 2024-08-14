#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define pbak push_back

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

    vector<int> output;
    output.pbak(N);

    int pos;
    for(pos=0;(1<<pos)!=N;pos++)
    {
        if((bool)(N&(1<<pos))==(bool)1)
        {
            N-=(1<<pos);
            output.pbak(N);
        }
    }

    for(pos=pos;pos>0;pos--)
    {
        N-=(1<<(pos-1));
        output.pbak(N);
    }

    cout<<output.size()<<endl;

    for(int &value : output)
    {
        cout<<value<<space;
    }
    cout<<endl;

    output.clear();
    }
    return 0;
}
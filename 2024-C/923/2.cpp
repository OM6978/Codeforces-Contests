#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int N;
    cin>>N;

    int arr[N],parity[26]={0};
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
        for(int j=0;j<26;j++)
        {
            if(arr[i]==parity[j])
            {
                parity[j]++;
                cout<<(char)(j + 97);
                break;
            }
        }
    }
    cout<<endl;

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
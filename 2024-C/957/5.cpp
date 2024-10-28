#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '

int countDigit(int n)
{
    if(n==0)return 1;

    int ans=0;
    while (n!=0)
    {
        n /= 10;
        ans++;
    }
    return ans;
}

string getrval(int n,int dig)
{
    int num = countDigit(n);

    string add = to_string(n);
    string ret;

    for(int i=0;i+num<=dig;i+=num)
        ret+=add;

    int j=0;
    for(int i=ret.size();i<dig;i++)
        ret.push_back(add[j++]);

    return ret;
}

bool verifythis(int n,int a,int b,int dig)
{
    int lval = n*a - b;
    int rval = stoi(getrval(n,dig));

    return (lval == rval);
}

void solve()
{
    int N;
    cin>>N;

    int nums = 0;
    vector<pair<int,int>> vpi;

    for(int a=1;a<=10000;a++)
    {
        int maxdigits = countDigit(N*a);
        int n_count = countDigit(N);
        int minb = n_count*a - maxdigits;

        for(int b=max(minb,1);b<minb + maxdigits && b<=10000;b++)
        {
            if(verifythis(N,a,b,n_count*a - b))
            {
                nums++;
                vpi.push_back({a,b});
            }
        }
    }

    cout<<nums<<endl;
    for(int i=0;i<vpi.size();i++)
    {
        cout<<vpi[i].first << sp <<vpi[i].second <<endl;
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
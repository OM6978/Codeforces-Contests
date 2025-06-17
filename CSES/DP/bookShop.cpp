#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 100;
const int maxX = 1e6;

int N, X, ar[maxN],br[maxN];
ll dp[maxX+1];

int main()
{
    scanf("%d %d", &N, &X);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &ar[i]);
    }

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &br[i]);
    }

    dp[0] = 0;
    for(int j = 0; j < N; j++)
    {
        for(int i = 0; i < X; i++)
        {
            if(i==0 || dp[i] != 0)
            {
                    if(i+ar[j] <= X)
                    {
                        dp[i+ar[j]] = max(dp[i+ar[j]],dp[i] + br[j]);
                    }
            }
        }
    }

    printf("%lld\n", *max_element(dp,dp + maxX+1));
}
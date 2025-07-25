#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 100;
const int maxX = 1e6;
const ll MOD = 1e9+7;

int N, X, ar[maxN];
ll dp[maxX+1];

int main()
{
    scanf("%d %d", &N, &X);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &ar[i]);
    }

    dp[0] = 1;
    for(int j = 0; j < N; j++)
    {
        for(int i = 0; i < X; i++)
        {
            if(dp[i]!=0)
            {
                if(i+ar[j] <= X)
                {
                    dp[i+ar[j]] = (dp[i+ar[j]] + dp[i]) % MOD;
                }
            }
        }
    }

    printf("%lld\n", dp[X]);
}
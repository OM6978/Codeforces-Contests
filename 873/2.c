#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int n1, int n2) {
    if (n2 != 0)
        return gcd(n2, n1 % n2);
    else
        return n1;
}

int main()
{
    int Test;
    scanf("%d",&Test);
    for(int i=0;i<Test;i++)
    {
    int N,ans,ans2;
    scanf("%d",&N);
    int diffarr[N+1],posarr[N+1],scanarr[N+1];
    for(int i=1;i<N+1;i++)
    {
        scanf("%d",&scanarr[i]);
        posarr[scanarr[i]]=i;
    }
    for(int i=1;i<N+1;i++)
    {
        diffarr[i]=abs(posarr[i]-i);
    }
    int i;
    for(i=1;i<N+1;i++)
    {
        ans=diffarr[i];
        if(ans!=0)
        {
            break;
        }
    }
    for(i=i;i<N+1;i++)
    {
        ans2=gcd(ans,diffarr[i]);
        if(ans2!=0){ans=ans2;}
    }
    printf("%d\n",ans);
    }
    return 0;
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    int Test;
    scanf("%d",&Test);
    for(int i=0;i<Test;i++)
    {
    int n,temp,stat=0,pig=0,max=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        if(temp==1)
        {
            pig++;
            stat++;
        }
        else
        {
            stat=pig/2+(stat!=0);
        }
        max= (stat>max)?stat:max;
    }
    printf("%d\n",max);
    }
    return 0;
}
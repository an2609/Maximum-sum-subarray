#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n+1];
    for(int i=1; i<=n; i++)
        scanf("%d",&ar[i]);
    int sum=ar[1],sum1=ar[1];
    for(int i=2; i<=n; i++)
    {
        sum+=ar[i];
        sum=max(sum,ar[i]);
        sum1=max(sum,sum1);
    }
    printf("%d\n",sum1);

}

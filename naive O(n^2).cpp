#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n+1];
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&ar[i]);
    }
    int ma=INT_MIN;
    for(int i=1; i<=n-1; i++)
    {
        int sum=ar[i];
        for(int j=i+1; j<=n; j++)
        {
            sum+=ar[j];
            if(sum>ma)
                ma=sum;
        }
    }
    cout<<ma<<endl;
}

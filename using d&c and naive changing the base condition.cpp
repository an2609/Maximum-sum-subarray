#include<bits/stdc++.h>
using namespace std;
int f(int ar[],int l,int mid,int h)
{
    int lmax=INT_MIN;
    int rmax=INT_MIN;
    int sum=0;
    for(int i=mid; i>=l; i--)
    {
        sum=sum+ar[i];
        if(sum>lmax)
            lmax=sum;
    }
    sum=0;
    for(int i=mid+1; i<=h; i++)
    {
        sum+=ar[i];
        if(sum>rmax)
            rmax=sum;
    }
    return lmax+rmax;
}
int maxsum(int ar[],int l,int h)
{
    //using divide and conquer with naive approach changing the base condition. clrs page 72 4.1-3.
    if(h-l<10)
    {
        int ma=INT_MIN;
        for(int i=l; i<=h-1; i++)
        {
            int sum=ar[i];
            for(int j=i+1; j<=h; j++)
            {
                sum+=ar[j];
                if(sum>ma)
                    ma=sum;
            }
        }
        return ma;
    }
    else
    {
        int mid=(l+h)/2;
        int leftmax=maxsum(ar,l,mid);
        int rightmax=maxsum(ar,mid+1,h);
        int cenmax=f(ar,l,mid,h);
        if(leftmax>=rightmax&&leftmax>=cenmax)
            return leftmax;
        else if(rightmax>=leftmax&&rightmax>=cenmax)
            return rightmax;
        else
            return cenmax;

    }
}
int main()
{
    int n;
    cin>>n;
    int ar[n+1];
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&ar[i]);
    }
    cout<<maxsum(ar,1,n);
}

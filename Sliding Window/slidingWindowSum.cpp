#include<bits/stdc++.h>
using namespace std;

// Input:
// 8 5  n,k
// 3 7 1 11   x_1=x
// x_i=(ax_{i-1}+b)mod c for i=2,3,\dots,n

// Output:
// 12

long long findSlidingSum(vector<long long >&arr,int n,int k)
{
    // fixed sliding window ques 
    //first calculate the sum for the first k elements and then apply sliding window 
    long long sum=0;
    long long ans_sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }
    ans_sum=ans_sum^sum;
    int i=0;int j=k;
    
    while(j<n)
    {
       if(j-i+1>k)
       {
        sum-=arr[i];
        i++;
       }
       sum+=arr[j];
       ans_sum^=sum;
       j++;

    }
    return ans_sum;

}
int main()
{
   long long n,k;
   cin>>n>>k;
   vector<long long>arr(n);
   long long x,a,b,c;
   cin>>x>>a>>b>>c;
   arr[0]=x;
   for(long long i=1;i<n;i++)
   {
     arr[i]=(a*arr[i-1]+b)%c;
   }
   
   cout<<findSlidingSum(arr,n,k)<<endl;

   return 0;
}
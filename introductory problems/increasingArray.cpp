#include<bits/stdc++.h>
using namespace std;
long long solve(int n,vector<int>&arr)
{
  //check for the number which does not satisfy the ascending operation and then take ans to be the prev- curr
  long long ans=0;
  for(int i=1;i<n;i++)
  {
       if(arr[i-1]>arr[i])
       {
        ans+=(arr[i-1]-arr[i]);
        arr[i]=arr[i-1];
       }
  }
  return ans;
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  cout<<solve(n,arr)<<endl;
  return 0;

}
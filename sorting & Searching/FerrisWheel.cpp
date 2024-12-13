#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,target;
  cin>>n>>target;
  vector<long long>arr(n);
  for(int i=0;i<n;i++)
  cin>>arr[i];

  sort(arr.begin(),arr.end());

  int i=0;
  int j=n-1;
  long long ans=0;
  while(i<=j)
  {
    if(arr[i]+arr[j]<=target)
    {
      ans++;
      arr[i]=-1;
      arr[j]=-1;
      i++;j--;
    }
    
    else
    j--;
  }
  for(auto it:arr)
  {
    if(it!=-1)
    ans++;
  }
  cout<<ans<<endl;
}
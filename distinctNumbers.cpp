#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long n;
  cin>>n;
  vector<long long>arr(n);
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  map<long long,long long>mp;
  for(auto it:arr)
  mp[it]++;

  long long ans=mp.size();
  cout<<ans<<endl;
  
}
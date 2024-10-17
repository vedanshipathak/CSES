#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long n,k;
  cin>>n>>k;
  vector<long long>arr(n);
  for(long long i=0;i<n;i++)
  cin>>arr[i];
 vector<pair<long long,long long>>p;
 for(long long i=0;i<n;i++)
 {
  p.push_back({arr[i],i+1});
 }
vector<long long>ans;
  //target sum question it is
  sort(p.begin(),p.end());//o(nlogn)
  long long i=0;long long j=n-1; int f=0;
  while(i<j)
  {
    long long sum=p[i].first+p[j].first;
    if(sum==k)
    {
      ans.push_back(p[i].second);
      ans.push_back(p[j].second);
      f++;
      break;
    }
    else if(sum>k)
    j--;
    else
    i++;
  }
  if(f==0)
  cout<<"IMPOSSIBLE"<<endl;
  else{
  for(auto it:ans)
  cout<<it <<" ";
  }
  return 0;

}
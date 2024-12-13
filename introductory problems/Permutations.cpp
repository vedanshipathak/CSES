#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int>&arr,int n)
{
  vector<int>odd;
  vector<int>even;
  for(auto it:arr)
  {
    if(it%2==0)
    even.push_back(it);
    else
    odd.push_back(it);
  }
  sort(even.begin(),even.end());
  sort(odd.begin(),odd.end());
  vector<int>ans;
  ans.insert(ans.end(),even.begin(),even.end());
  ans.insert(ans.end(),odd.begin(),odd.end());
  return ans;
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr;
  for(int i=1;i<=n;i++)
  {
    arr.push_back(i);
  }
  if(n==1)
  cout<<1<<endl;

  else if(n>3)
  {
  vector<int> ans=solve(arr,n);
  for(auto it:ans)
  {
    cout<<it<<" ";
  }
  }
  else
  cout<<"NO SOLUTION"<<endl;
  return 0;
}
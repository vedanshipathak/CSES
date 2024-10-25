#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,q;
  cin>>n>>q;
  vector<long long>arr(n);
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  vector<long long>pre(n);
  pre[0]=arr[0];
  for(int i=1;i<n;i++)
  {
    pre[i]=pre[i-1]+arr[i];
  }
  while(q--)
  {
    int a,b;
    cin>>a>>b;
    if(a==b)
    cout<<arr[a-1]<<endl;
    else if(a==1)
    cout<<pre[b-1]<<endl;
    else
    cout<<pre[b-1]-pre[a-2]<<endl;
  }
}
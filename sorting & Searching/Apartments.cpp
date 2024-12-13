#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long n,m,k;
  cin>>n>>m>>k;
  vector<long long>a(n);
  for(long long i=0;i<n;i++)
  {
    cin>>a[i];
  }
  vector<long long>b(m);
  for(long long i=0;i<m;i++)
  cin>>b[i];

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  long long ans=0;
  long long i=0;long long j=0;
  while(i<n && j<m)
  {
    if(b[j]>=(a[i]-k) && b[j]<=(a[i]+k))
    {
      ans++;
      i++;
      j++;
    }
    else if(b[j]<a[i]-k)
    {
       j++;
    }
    else
    i++;
  }
  cout<<ans<<endl;
  return 0;
}
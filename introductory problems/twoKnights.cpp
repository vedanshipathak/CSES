#include<bits/stdc++.h>
using namespace std;
long long giveVal(int k)
{long long ans=0;
    long long total_ways=(1LL*(k*k)*(k*k-1))/2;
    //no subtract the ways in whch the knights can attack from the total ways
    long long two_cross_three_mat=1LL*(k-1);
    long long three_cross_two_mat=1LL*(k-2);
    //give the ans
     ans=total_ways-4*1LL*(two_cross_three_mat*three_cross_two_mat);

  return ans;
}
int main()
{
  long long k;
  cin>>k;
  //the answer will be stored in long long as the constraint is from 1 to 10000
  for(long long i=1;i<=k;i++)
  {
    cout<<giveVal(i)<<endl;
  }
  return 0;
}
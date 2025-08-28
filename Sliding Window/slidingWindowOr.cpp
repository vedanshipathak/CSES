#include<bits/stdc++.h>
using namespace std;
using ll=long long;
class Solve{
    public:
    ll solve(vector<ll>&arr, ll n ,ll k)
    {
          ll i=0,j=0;
          ll sum=0;
          ll ans=0;
          while(j<n)
          {    
              //shirnk
              
                ans=ans^sum;
                i++;
              
              //expand 
             
               sum=sum | arr[j];
              j++;

          }

          return ans;
    }
};
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    arr[0]=x;
    for(ll i=1;i<n;i++)
    {
        arr[i]=(a*x+b)%c;
    }
    Solve obj;
    cout<< obj.solve(arr,n,k);
}
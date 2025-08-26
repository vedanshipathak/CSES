#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll slidingWindowXor(vector<ll>& arr, ll n, ll k)
{
    ll curr_xor=0;
    ll ans=0;
 
    // first window
    for(ll i=0;i<k;i++)
        curr_xor ^= arr[i];
    ans ^= curr_xor;

    ll i=0, j=k;
    while(j<n)
    {     
        curr_xor ^= arr[i]; // remove outgoing
        i++;
        curr_xor ^= arr[j]; // add incoming
        ans ^= curr_xor;
        j++;
    }
    return ans;
}
 
int main()
{

   ll n,k;
   cin>>n>>k;
   vector<ll> arr(n);
   ll x,a,b,c;
   cin>>x>>a>>b>>c;
   arr[0] = x;
   for(ll i=1;i<n;i++) {
       arr[i] = (a*arr[i-1] + b) % c;
   }

   cout << slidingWindowXor(arr,n,k) << "\n";
}

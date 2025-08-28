#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<int> solve(vector<ll>&arr,int n,int k)
{
    unordered_map<ll,int>mp;
    int i=0;int j=0;
    int windows=n-k+1;

    vector<int>ans;
    while(j<n)
    {
        //check if the window size increases 
        if(j-i+1>k)
        {   ans.push_back(mp.size());
               
                mp[arr[i]]--;
                if(mp[arr[i]]==0)mp.erase(arr[i]);
            i++;
        }
        //else expand
        mp[arr[j]]++;
        j++;
        
    }
    ans.push_back(mp.size());
    
    return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   vector<int> ans=solve(arr,n,k);
   for(auto it:ans)
   cout<<it<<" ";
   cout<<endl;
   return 0;
}
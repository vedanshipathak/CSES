#include <bits/stdc++.h>
using namespace std;

pair<long long,long long>solve(int mask,int n,vector<long long>&arr,long long W,vector<pair<long long,long long>>&dp)
{
    //base case
    if(dp[mask].first!=-1)
    return dp[mask];
    
    pair<long long ,long long>best={LLONG_MAX,LLONG_MAX};
    //take every element not taken yet
    for(int i=0;i<n;i++)
    {
        if(!(mask & (1<<i)))
        {
            auto prev=solve((mask|(1<<i)),n,arr,W,dp);
            long long rides=prev.first;
            long long wt=prev.second;
            
            if(wt+arr[i]<=W)
            {
                best=min(best,{rides,wt+arr[i]});
            }
            else
            best=min(best,{rides+1,arr[i]});
        }
    }
    return dp[mask]=best;
}
int main() {
	// your code goes here
	int n;	long long W;

	cin>>n>>W;
	vector<long long>arr(n);
	for(int i=0;i<n;i++)
	cin>>arr[i];
	

	
	vector<pair<long long ,long long>>dp;
	dp.assign((1<<n),make_pair(-1,-1));
	dp[(1<<n)-1]={1,0};
	 
	 int mask=0;
	pair<long long,long long>p=solve(mask,n,arr,W,dp);
	cout<<p.first<<endl;
	return 0;

}

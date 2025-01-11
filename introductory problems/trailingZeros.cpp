#include<bits/stdc++.h>
using namespace std;

int main()
{

	long long n,ans=0; cin>>n;
	for(int i=5;i<=n;i*=5) ans+=n/i;
	cout<<ans<<"\n";
	return 0;
}

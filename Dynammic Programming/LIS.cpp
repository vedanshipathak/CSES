// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//   long long n;
//   cin>>n;
//   vector<long long>arr(n);
//   for(long long i=0;i<n;i++)
//   {
//     cin>>arr[i];
//   }
//   //create an array of all uniquee elements in the array in sorted order
//   set<long long>s;
//   for(auto it:arr)
//   s.insert(it);
//   vector<long long>temp;
//   for(auto it:s)
//   temp.push_back(it);

//   sort(temp.begin(),temp.end());
//   long long m=temp.size();
//   //now declare the dp 
//   long long dp[n+1][m+1];
//   //base condition
//   for(long long i=0;i<n+1;i++)
//   {
//     for(long long j=0;j<m+1;j++)
//     {
//       if(i==0||j==0)
//       dp[i][j]=0;
//     }
//   }
//   //initialize the choice diagram 
//   for(long long i=1;i<n+1;i++)
//   {
//     for(long long j=1;j<m+1;j++)
//     {
//       if(arr[i-1]==temp[j-1])
//       dp[i][j]=1+dp[i-1][j-1];
//       else
//       dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
//     }

//   }
//   cout<<dp[n][m]<<endl;
//   return 0;
// }


#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
public:
    vector<long long> bit;  // Fenwick Tree array
    long long n;

    FenwickTree(long long size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    // Update the Fenwick Tree at position idx with value val
    void update(long long idx, long long val) {
        while (idx <= n) {
            bit[idx] = max(bit[idx], val);
            idx += idx & -idx;
        }
    }

    // Query the maximum value in the range [1, idx]
    long long query(long long idx) {
        long long res = 0;
        while (idx > 0) {
            res = max(res, bit[idx]);
            idx -= idx & -idx;
        }
        return res;
    }
};

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 1: Coordinate compression
    set<long long> s(arr.begin(), arr.end());
    vector<long long> temp(s.begin(), s.end());
    unordered_map<long long, long long> compress;
    for (long long i = 0; i < temp.size(); i++) {
        compress[temp[i]] = i + 1;  // Compressed index starts from 1 for Fenwick Tree
    }

    // Step 2: Fenwick Tree to maintain the dynamic programming state
    FenwickTree fenwick(temp.size());

    long long result = 0;

    // Step 3: Calculate the longest increasing subsequence
    for (long long i = 0; i < n; i++) {
        long long compressed_val = compress[arr[i]];
        long long best = fenwick.query(compressed_val - 1) + 1;  // Get the best LIS ending at arr[i]
        fenwick.update(compressed_val, best);  // Update the Fenwick Tree with the new best LIS length
        result = max(result, best);  // Track the maximum LIS found
    }

    // Step 4: Output the result
    cout << result << endl;

    return 0;
}

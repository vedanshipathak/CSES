#include<bits/stdc++.h>
using namespace std;
//here the approach is to use dp with tries
//tries majorly helps in navigating in dictionary 
//search and insert features 
//here each  char is treated as nodes

class Trie{
    public:
    
   Trie* child[26];
   bool isEnd;
   Trie* root;
   Trie()
   {
     isEnd=false;
     for(int i=0;i<26;i++)
     {
        child[i]=NULL;
     }
     root=this;
   }
   //insert function
   void insert(string s)
   {
    int n=s.size();
    Trie* curr=root;
    for(int i=0;i<n;i++)
    {
        int idx=s[i]-'a';
        if(curr->child[idx]==NULL)
        curr->child[idx]=new Trie();
        curr=curr->child[idx];
    }
    curr->isEnd=true;

   }

   bool search(string s)
   {
    int n=s.size();
    Trie* curr=root;
    for(int i=0;i<n;i++)
    {
        int idx=s[i]-'a';
        if(curr->child[idx]==NULL)return false;
        curr=curr->child[idx];
    }
    return curr->isEnd;
   }
   const int MOD=1e9+7;
   long long countWays(int i, const string &s, vector<long long> &dp) {
    if(i == s.size()) return 1;
    if(dp[i] != -1) return dp[i];

    long long res = 0;
    Trie* curr = root;  // start from root

    // traverse the Trie along s[i..]
    for(int j = i; j < s.size(); j++) {
        int idx = s[j] - 'a';
        if(curr->child[idx] == nullptr) break; // no match
        curr = curr->child[idx];
        if(curr->isEnd) {
            res = (res + countWays(j + 1, s, dp)) % MOD;
        }
    }

    return dp[i] = res;
}

};
int main()
{
    //create the tries
    
    string str;
    cin>>str;
    int n;
    cin>>n;
    
    Trie obj;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        obj.insert(word);
    }
    vector<long long>dp(str.size()+1,-1);
    cout<<obj.countWays(0,str,dp);
}
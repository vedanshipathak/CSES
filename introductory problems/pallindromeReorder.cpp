#include<bits/stdc++.h>
using namespace std;

int main()
{
  string str;
  cin>>str;
  unordered_map<char,int>mp;
  for(auto it:str)
  mp[it]++;
  //now check if more than 2 odds the ans is not valid 
  int c=0;
  for(auto it:mp)
  {
    if(it.second%2!=0)
     c++;

  }
  if(c>1)
  cout<<"NO SOLUTION"<<endl;
  else
  {
     string pre;
     string suff="";
     string mid;
     for (auto &it : mp) {
        string temp(it.second / 2, it.first); // Half of the even characters
        pre += temp;
        suff = temp + suff;                  // Mirror for suffix
        if (it.second % 2 != 0) {
            mid += it.first;                 // Add odd character in the middle
        }
    
  }
  //  cout<<pre<<" "<<suff<<" "<<mid<<endl;
     string ans=pre+mid+suff;
     cout<<ans<<endl;
}
}
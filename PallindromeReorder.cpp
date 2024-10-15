#include<bits/stdc++.h>
using namespace std;
string rearrange(string s)
{
   //we can use hashmaps 
   unordered_map<char,int>mp;
   for(auto it:s)
   {
    mp[it]++;
   }
   int count=0;string f="",l="",c="";
   for(auto it:mp)
   {
    if(it.second==1)
    count++;
    if(it.second%2==0 && it.second>0)
    {
      f=it.first+f;
      it.second--;
      l=l+it.first;
      it.second--;
    }
    else
    {
       f=it.first+f;
      it.second--;
      l=l+it.first;
      it.second--;
      c=c+it.first;
      it.second--;
     }
   }
   if(count>1)
   return "";
   return f+c+l;
}
int main()
{
  string s="AAABBCC";
  // cin>>s;
  if(rearrange(s)=="")
  cout<<"NO SOLUTION"<<endl;
  else
  cout<<rearrange(s)<<endl;
  return 0;
}
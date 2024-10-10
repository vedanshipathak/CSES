// here the ques says if we hacve 2 piles of coin 
// we can ither remove 1 from left and 2 form right
// OR
// two from left one from right 
// can we make both zero or not

// approach: while looking you would realize if both sum is divible by 3 and the one with min val * 2 is greater than max value  then yes else no
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int a,b;
    cin>>a>>b;
    if((a+b)%3==0 && (min(a,b)*2>=max(a,b)))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
  }
  return 0;
}

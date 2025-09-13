#include<iostream>
#include<queue>
#include<string>
using namespace std;
string non_repeated(string A)
{
  string B;
  vector<int>repeated(26,0);
  queue<char>q;

  for(int i=0;i<A.size();i++)
  {
    if(repeated[A[i]-'a']>=1)
    {
      repeated[A[i]-'a']++;
      while(!q.empty() &&repeated[q.front()-'a']>1)
      {
        q.pop();
      }
      if(q.empty())
      {
        B+="-1";
      }
      else
      {
        B+=q.front();
      }
    }
    else{
      repeated[A[i]-'a']++;
      q.push(A[i]);
      while(repeated[q.front()-'a']>1)
      {
        q.pop();
      }
    
        B+=q.front();
      }
    }
    return B;
  }
  int main()
  {
    string A="aabc";
    cout<<non_repeated(A);
  }
//time complexity == O(n)

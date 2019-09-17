#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;


vector<string> deal(string str)
{
   vector<string> res;
   for (int i = 0; i < str.size(); ++i) {
       int j=i;
       while(i < str.size()&&str[i]!='.')
           i++;
       res.push_back(str.substr(j,i-j));
   }
   while(res.size()!=4&&res.front()=="*")
       res.insert(res.begin(),"*");
   while(res.size()!=4&&res.back()=="*")
       res.push_back("*");
   return res;

}


int main()
{
   int n,m;
   cin>>n>>m;
   cin.ignore();
   vector<vector<string>> rules;
   vector<vector<string>> test;
   for (int i = 0; i < n; ++i) {
       string str;
       getline(cin,str);
       rules.push_back(deal(str));
   }
   for (int j = 0; j < m; ++j) {
       string str;
       getline(cin,str);
       test.push_back(deal(str));
   }
   for(auto list:test)
   {
       int flag;
       for(auto rule:rules)
       {
            flag=1;
           for (int i = 0; i < 4; ++i) {
               if(list[i]!=rule[i]&&rule[i]!="*")
               {
                   flag=0;
                   break;
               }
           }
           if(flag==1)
               break;
       }
       cout<<flag<<" ";
   }
   return 0;
}




#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
int maxseq(vector<int>& num)
{
   int n=num.size();
   if(n<2)
       return 0;
   vector<vector<int>> dp(n,vector<int>(n,1));
   int ans=1;
   for (int i = 0; i < n-1; ++i)
       for (int j = i+1; j < n; ++j) {
           int k=0;
           for (int t = 0; t < i; ++t) {
               if(num[i]-num[t]==num[j]-num[i])
                   k=max(k,dp[t][i]);

           }
           dp[i][j]+=k;
           ans=max(ans,dp[i][j]);
       }
   return ans+1;
}

int main()
{
   int m;
   cin>>m;
   vector<int> num(m,0);
   for (int i = 0; i < m; ++i) {
       cin>>num[i];
   }
   sort(num.begin(),num.end());
   cout<<maxseq(num);
   return 0;
}

#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<int>&wt , vector<int>&val ,int ob, int W)
{
    vector<vector<int>> dp(ob, vector<int>(W+1 , 0));
    for(int i=wt[0] ; i<=W ; i++)
    {
    dp[0][i]=val[0];
    }
    for(int ind=1; ind<ob; ind++)
    {
        for(int j=0;j<=W;j++)
        {
            int nottaken=dp[ind-1][j];
            int taken=INT_MIN;

            if(wt[ind]<=j){
            taken=val[ind]+dp[ind-1][j-wt[ind]];
        }
        dp[ind][j]=max(nottaken,taken);
    }
}return dp[ob-1][W];  }
int main()
{
    int ob;
    cin>>ob;
    vector<int> wt(ob);
   vector<int> val(ob);
   for(int i=0;i<ob;i++)
   {
    cin>>wt[i]>>val[i];
   }
    
   int W;
   cin>>W;
   cout<<knapsack(wt,val,ob,W);
}
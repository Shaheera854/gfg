//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int mod=1e9+7;
    int solve(int ind1,int ind2,string s,string t,int n1,int n2,vector<vector<int>> &dp){
        if(ind2==n2)
        return 1;
        if(ind1==n1)
        return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        int c=0;
        if(s[ind1]==t[ind2]){
            c+=solve(ind1+1,ind2+1,s,t,n1,n2,dp);
            c%=mod;
        }
        c+=solve(ind1+1,ind2,s,t,n1,n2,dp);
        c%=mod;
        return dp[ind1][ind2]=c%mod;
    }
    int subsequenceCount(string s, string t)
    {
      //Your code here
      int n1=s.size();
      int n2=t.size();
      vector<vector<int>> dp(n1,vector<int>(n2,-1));
      return solve(0,0,s,t,n1,n2,dp);
    }
};


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends
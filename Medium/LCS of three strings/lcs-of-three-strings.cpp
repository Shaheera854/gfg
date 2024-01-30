//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int solve(int i,int j,int k,string &A,string &B,string &C,vector<vector<vector<int>>>&dp){
            if(i==A.size() or j==B.size() or k==C.size())
            return 0;
            if(dp[i][j][k]!=-1)return dp[i][j][k];
            if(A[i]==B[j] and B[j]==C[k]){
                dp[i][j][k]=1+solve(i+1,j+1,k+1,A,B,C,dp);
                return dp[i][j][k];
            }
            int a=solve(i+1,j,k,A,B,C,dp);
            int b=solve(i,j+1,k,A,B,C,dp);
            int c=solve(i,j,k+1,A,B,C,dp);
            dp[i][j][k]=max(a,b);
            dp[i][j][k]=max(dp[i][j][k],c);
            return dp[i][j][k];
        }
        int LCSof3 (string A, string B, string C,int n1,int n2,int n3)
        {
            // your code here
            vector<vector<vector<int>>>dp(A.size(),vector<vector<int>>(B.size(),vector<int>(C.size(),-1)));
            return solve(0,0,0,A,B,C,dp);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
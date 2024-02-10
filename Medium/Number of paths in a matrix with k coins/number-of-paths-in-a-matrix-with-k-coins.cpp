//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long solve(int i,int j,int n,int k,vector<vector<int>> &arr,vector<vector<vector<long long>>> &dp){
        if(i==n-1 and j==n-1){
            if(k==arr[i][j])
            return 1;
            return 0;
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        long long c=0;
        if(i<n-1 and k>arr[i][j])
        c+=solve(i+1,j,n,k-arr[i][j],arr,dp);
        if(j<n-1 and k>arr[i][j])
        c+=solve(i,j+1,n,k-arr[i][j],arr,dp);
        return dp[i][j][k]=c;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        // Code Here
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>> (n+1,vector<long long> (k+1,-1)));
        return solve(0,0,n,k,arr,dp);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends
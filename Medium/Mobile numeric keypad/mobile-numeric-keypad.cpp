//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long solve(int i,int j,int n,vector<vector<vector<long long>>> &dp){
        if(i==4 or i<0 or j==3 or j<0 or (i==3 and j==0) or (i==3 and j==2)) return 0;
        if(n==1) return 1;
        if(dp[i][j][n]!=-1)return dp[i][j][n];
        long long c=0;
        c+=solve(i,j,n-1,dp)+solve(i+1,j,n-1,dp)+solve(i-1,j,n-1,dp)+solve(i,j+1,n-1,dp)+solve(i,j-1,n-1,dp);
        return dp[i][j][n]=c;
    }
    long long getCount(int n) {
        // Your code goes here
        map<int,pair<int,int>> mpp;
        mpp[0]={3,1};
        mpp[1]={0,0};
        mpp[2]={0,1};
        mpp[3]={0,2};
        mpp[4]={1,0};
        mpp[5]={1,1};
        mpp[6]={1,2};
        mpp[7]={2,0};
        mpp[8]={2,1};
        mpp[9]={2,2};
        long long c=0;
        vector<vector<vector<long long>>> dp(4,vector<vector<long long>>(3,vector<long long> (26,-1)));
        for(int i=0;i<10;i++){
            c+=solve(mpp[i].first,mpp[i].second,n,dp);
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends
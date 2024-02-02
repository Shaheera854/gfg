//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int solve(long long int sum,long long int N,int coins[],vector<vector<long long int>>& dp){
        if(sum==0){
            return 1;
        }
        if(N<0 or sum<0){
            return 0;
        }
        if(dp[sum][N]!=-1)return dp[sum][N];
        long long int p=solve(sum-coins[N],N,coins,dp);
        long long int np=solve(sum,N-1,coins,dp);
        return dp[sum][N]=p+np;
        }
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>> dp(sum+1,vector<long long int>(N,-1));
        return solve(sum,N-1,coins,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
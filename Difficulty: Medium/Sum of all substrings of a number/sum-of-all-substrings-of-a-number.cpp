class Solution {
  public:
    int solve(int ind,string &s,vector<int> &dp){
       if(ind >= s.size())
       return 0;
       dp[ind] = dp[ind-1]*10 + (s[ind]-'0')*(ind+1);
       int res = dp[ind] + solve(ind+1,s,dp);
       return res;
    }
    int sumSubstrings(string &s) {
        // code here
        int size = s.size();
        vector<int> dp(size,-1);
        int val = s[0] - '0';
        dp[0] = val;
        return solve(1,s,dp) + val;
    }
};
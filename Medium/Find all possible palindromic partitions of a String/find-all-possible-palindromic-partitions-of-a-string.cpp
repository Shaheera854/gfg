//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool ispal(string s2){
        int n=s2.size();
        for(int i=0;i<n/2;i++){
            if(s2[i]!=s2[n-i-1])
            return false;
        }
        return true;
    }
    void solve(int ind,int n,string S,vector<string> v,vector<vector<string>> &res){
        if(ind==n){
            res.push_back(v);
            return;
        }
        for(int i=ind;i<n;i++){
            string s1=S.substr(ind,i-ind+1);
            if(ispal(s1)){
                v.push_back(s1);
                solve(i+1,n,S,v,res);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<string> v;
        vector<vector<string>> res;
        int n=S.size();
        solve(0,n,S,v,res);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
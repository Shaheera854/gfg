//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        vector<int> res;
        res.push_back(0);
        res.push_back(1);
        int a=0,b=1,c=1;
        for(int i=0;i<=n-2;i++){
            res.push_back(c%1000000007);
            a=b;
            b=c;
            c=(a%1000000007+b%1000000007)%1000000007;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
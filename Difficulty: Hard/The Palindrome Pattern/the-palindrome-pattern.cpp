//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool ispal(string s){
        for(int i = 0 ; i < s.size()/2 ; i++){
            if(s[i] != s[s.size()-i-1])
            return false;
        }
        return true;
    }
    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            string s1 = "";
            for(int j = 0 ; j < n ; j++){
                s1+=arr[i][j];
            }
            if(ispal(s1)){
                string res = to_string(i) + " R";
                return res;
            }
        }
        for(int i = 0 ; i < n ; i++){
            string s1 = "";
            for(int j = 0 ; j < n ; j++){
                s1+=arr[j][i];
            }
            if(ispal(s1)){
                string res = to_string(i) + " C";
                return res;
            }
        }
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends
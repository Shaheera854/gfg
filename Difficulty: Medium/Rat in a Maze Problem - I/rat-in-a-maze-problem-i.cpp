//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void solve(int i,int j,vector<vector<int>> &mat,string s,vector<vector<bool>> &vis,vector<string> &res){
        if(i == mat.size()-1 and j == mat.size()-1){
            res.push_back(s);
            return;
        }
        vis[i][j] = true;
        if(i+1 >= 0 and i+1 < mat.size() and mat[i+1][j] == 1 and !vis[i+1][j]){
            solve(i+1,j,mat,s+'D',vis,res);
            // s -= 'D';
        }
        if(i-1 >= 0 and i-1 < mat.size() and mat[i-1][j] == 1 and !vis[i-1][j]){
            // s += 'U';
            solve(i-1,j,mat,s+'U',vis,res);
            // s -= 'U';
        }
        if(j+1 >= 0 and j+1 < mat.size() and mat[i][j+1] == 1 and !vis[i][j+1]){
            // s += 'R';
            solve(i,j+1,mat,s+'R',vis,res);
            // s -= 'R';
        }
        if(j-1 >= 0 and j-1 < mat.size() and mat[i][j-1] == 1 and !vis[i][j-1]){
            // s += 'L';
            solve(i,j-1,mat,s+'L',vis,res);
            // s -= 'L';
        }
        vis[i][j] = false;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        if(mat[0][0] == 0)
        return {"-1"};
        vector<string> res;
        int n = mat.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        solve(0,0,mat,"",vis,res);
        if(res.size() == 0)
        return {"-1"};
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
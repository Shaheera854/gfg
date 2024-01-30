//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int dRow[4]={0,0,-1,1};
    int dCol[4]={-1,1,0,0};
    vector<char> v={'L','R','U','D'};
    bool isValid(int r,int c,int &n,vector<vector<int>> &vis,vector<vector<int>> &m){
        if(r<0 or c<0 or r>=n or c>=n or vis[r][c] or m[r][c]==0)
        return false;
        return true;
    }
    void solve(int i,int j,int n,string s,vector<string> &res,vector<vector<int>> &m,vector<vector<int>> &vis){
        if(i==n-1 and j==n-1){
            res.push_back(s);
            return;
        }
        for(int k=0;k<4;k++){
            int x,y;
            x=i+dRow[k];
            y=j+dCol[k];
            if(isValid(x,y,n,vis,m)){
                s+=v[k];
                vis[x][y]=1;
                solve(x,y,n,s,res,m,vis);
                s.pop_back();
                vis[x][y]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> vis(n,vector<int>(n,0));
        string s="";
        vector<string> res;
        if(m[0][0]==0)
        return res;
        vis[0][0]=1;
        solve(0,0,n,s,res,m,vis);
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
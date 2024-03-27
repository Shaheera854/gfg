//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    bool isSafe(int r, int c, vector<vector<int>> &mat){
        int n = mat.size();
        int m = mat[0].size();
        
        if(r<0 || r>=n || c<0 || c>=m || mat[r][c]==0) return false;
        if(r-1>=0 && mat[r-1][c]==0) return false;
        if(r+1<n && mat[r+1][c]==0) return false;
        if(c-1>=0 && mat[r][c-1]==0) return false;
        if(c+1<m && mat[r][c+1]==0) return false;
        
        return true;
    }
    
    int dfs(int r, int c, vector<vector<int>> &mat, vector<vector<int>> &vis){
        if(c == mat[0].size()-1) return 0;
        
        vis[r][c] = 1;
        int ans = 1e8;
        
        //up
        if(isSafe(r-1,c,mat) && !vis[r-1][c]){
            ans = min(ans,1+dfs(r-1,c,mat,vis));
        }
        
        //down
        if(isSafe(r+1,c,mat) && !vis[r+1][c]){
            ans = min(ans,1+dfs(r+1,c,mat,vis));
        }
        
        //front
        if(isSafe(r,c+1,mat) && !vis[r][c+1]){
            ans = min(ans,1+dfs(r,c+1,mat,vis));
        }
        
        vis[r][c] = 0;
        return ans;
    }
    
    int findShortestPath(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = 1e8;
        for(int i=0; i<n; i++){
            if(isSafe(i,0,mat)){
                ans = min(ans,1+dfs(i,0,mat,vis)); 
            }
        }
        if(ans == 1e8) return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
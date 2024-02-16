//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    void dfs(int node,vector<int> adj[],vector<int> &vis,vector<bool> &visited,int &fl){
        visited[node]=true;
        vis[node]=1;
        for(auto it:adj[node]){
            if(!visited[it])
            dfs(it,adj,vis,visited,fl);
            else if(vis[it]){
                fl=1;
                return;
            }
        }
        vis[node]=0;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                vector<int> vis(V,0);
                int fl=0;
                dfs(i,adj,vis,visited,fl);
                if(fl==1)
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
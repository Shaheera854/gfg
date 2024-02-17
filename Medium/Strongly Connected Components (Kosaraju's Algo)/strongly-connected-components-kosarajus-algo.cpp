//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<int> adj2[],vector<bool> &vis,vector<int> &v){
	vis[node]=1;
	for(auto it:adj2[node]){
		if(!vis[it]){
			dfs(it,adj2,vis,v);
		}
	}
	v.push_back(node);
	}
void dfs(int node,vector<int> adj1[],vector<bool> &visited){
	visited[node]=1;
	for(auto it:adj1[node]){
		if(!visited[it]){
			dfs(it,adj1,visited);
		}
	}
}
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        //code here
        vector<int> adj2[n];
        int e=adj.size();
    	for(int i=0;i<e;i++){
    	    for(auto it:adj[i])
    		adj2[i].push_back(it);
    	}
    	vector<int> v;
    	vector<bool> vis(n,false);
	for(int i=0;i<n;i++){
		if(!vis[i])
			dfs(i,adj2,vis,v);
	}
	reverse(v.begin(),v.end());
	vector<int> adj1[n];
	for(int i=0;i<e;i++){
	    for(auto it:adj[i]){
	        adj1[it].push_back(i);
	    }
	}
	vector<bool> visited(n,false);
	int c=0;
	for(int i=0;i<n;i++){
		if(!visited[v[i]]){
			c++;
			dfs(v[i],adj1,visited);
		}
	}
	    return c;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
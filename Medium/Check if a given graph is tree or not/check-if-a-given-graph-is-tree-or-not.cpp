//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        vector<int> graph[n];
        //vector<int> indegree(n,0);
        //cout<<n<<" ";
        for(int i=0;i<m;i++){
            graph[adj[i][0]].push_back(adj[i][1]);
            graph[adj[i][1]].push_back(adj[i][0]);
        }
        queue<pair<int,int>> q;
        q.push({0,-1});
        vector<int> vis(n,0);
        while(!q.empty()){
            int temp1=q.front().first;
            int temp2=q.front().second;
            if(temp1==temp2)
            return 0;
            q.pop();
            for(auto it:graph[temp1]){
                if(vis[it]){
                    if(temp2!=-1 and it!=temp2)
                    return 0;
                }
                else{
                    q.push({it,temp1});
                }
            }
            vis[temp1]=1;
        }
        for(auto it:vis){
            if(it==0)
            return 0;
        }
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
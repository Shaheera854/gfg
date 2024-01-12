//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        if(*min_element(frogs,frogs+N)==1)
        return 0;
        vector<int> vis(leaves+1,0);
        vis[0]=1;
        for(int i=0;i<N;i++){
            if(frogs[i]<=leaves and !(vis[frogs[i]])){
                for(int j=frogs[i];j<leaves+1;j+=frogs[i]){
                    vis[j]=1;
                }
            }
        }
        int c=0;
        for(int i=0;i<leaves+1;i++){
            //cout<<vis[i]<<" ";
            if(!vis[i])
            c++;
        }
        return c;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         int n = mat.size();
         vector<int> ans(n*n);
         int k = 0;
         int i = 0, j=0;
         while(i<n && i>=0 && j>=0 && j<n){
             while(i>=0 && j<n){
                 ans[k] = mat[i][j];
                 i--;
                 j++;
                 k++;
             }
             if(j==n){
                 i+=2;
                 j--;
             }else{
                 i=0;
             }
             while(i<n && j>=0){
                 ans[k] = mat[i][j];
                 i++;
                 j--;
                 k++;
             }
             if(i==n){
                 j+=2;
                 i--;
             }else{
                 j=0;
             }
         }
         return ans;
    }


};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends
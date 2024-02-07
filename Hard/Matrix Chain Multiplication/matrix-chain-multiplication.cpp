//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int> (N,INT_MAX));
        for(int i=0;i<N;i++){
            dp[i][i]=0;
        }
        for(int x=0;x<N;x++){
            int i=0,j=x+1;
            while(i<N and j<N){
                for(int k=i;k<j;k++){
                    if(i!=0)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
                    else
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[k]*arr[j]);
                }
                i++;
                j++;
            }
        }
        /*for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return dp[1][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
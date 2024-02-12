//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long mod=1e9+7;
    void solve(int ind,int num,int n,long long &ans){
        if(ind>n)return;
        int temp=ind;
        int p=1;
        while(temp--){
            p=(p%mod*num%mod)%mod;
            num++;
            num%=mod;
        }
        ans+=p;
        ans%=mod;
        solve(ind+1,num,n,ans);
    }
    long long sequence(int n){
        // code here
        long long ans=0;
        solve(1,1,n,ans);
        return ans%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
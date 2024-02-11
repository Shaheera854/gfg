//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        vector<int> res;
        res.push_back(0);
        map<int,int> mpp;
        mpp[0]++;
        for(int i=1;i<n;i++){
            int x=res[i-1]-i;
            if(x>0 and mpp.find(x)==mpp.end()){
                res.push_back(x);
            }
            else
            res.push_back(res[i-1]+i);
            mpp[res[res.size()-1]]++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
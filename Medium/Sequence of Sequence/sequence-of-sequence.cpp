//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
//static int c=0;
class Solution{
public:
    void dp(int ind,int n,int m,vector<int> &v,int &c){
        if(v.size()==n){
            c++;
            return;
        }
        for(int i=ind*2;i<=m;i++){  
            v.push_back(i);
            dp(i,n,m,v,c);
            v.pop_back();
        }
    }
    int numberSequence(int m, int n){
        // code here
        int c=0;
        for(int i=1;i<=m/n;i++){
            vector<int> v;
            v.push_back(i);
            dp(i,n,m,v,c);
        }
        return c;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
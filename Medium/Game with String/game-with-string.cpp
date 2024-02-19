//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        map<char,int> mpp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        vector<int> v;
        for(auto it:mpp)
        v.push_back(it.second);
        sort(v.begin(),v.end());
        int size=v.size();
        vector<int> res(v[size-1]+1);
        for(int i=0;i<size;i++)
        res[v[i]]++;
        int size1=res.size();
        int maxi=v[size-1];
        while(k-- and maxi){
            res[maxi]--;
            res[maxi-1]++;
            if(res[maxi]==0)
            maxi--;
        }
        int c=0;
        for(int i=1;i<size1;i++){
            c+=(i*i*res[i]);
        }
        return c;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
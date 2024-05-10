//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve(vector<int> &arr,int ind,int n,int k,int sum,vector<int> &v,set<vector<int>> &res){
        if(sum==k){
            res.insert(v);
            return;
        }
        else if(sum>k)
        return;
        if(ind==n)
        return;
        v.push_back(arr[ind]);
        solve(arr,ind+1,n,k,sum+arr[ind],v,res);
        v.pop_back();
        solve(arr,ind+1,n,k,sum,v,res);
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(),arr.end());
        set<vector<int>> res;
        vector<int> v;
        solve(arr,0,n,k,0,v,res);
        vector<vector<int>> ans;
        for(auto it:res){
            ans.push_back(it);
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
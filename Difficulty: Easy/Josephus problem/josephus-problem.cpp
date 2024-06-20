//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    void solve(int st, vector<int> &v, int k, int &ans){
        // cout<<st<<" ";
        if(v.size()==1)
        {
            ans = v[0];
            return;
        }
        int ind = (st+k-1)%v.size();
        v.erase(v.begin()+ind);
        solve(ind, v, k, ans);
    }
    int josephus(int n, int k)
    {
       //Your code here
       //int sum = (n*(n+1))/2;
       int ans = -1;
       vector<int> v(n);
       for(int i=0;i<n;i++)
       v[i] = i+1;
       solve(0,v,k,ans);
       return ans;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends
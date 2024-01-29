//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(int x,int y,int n,string &s,vector<string>&res){
        if(s.size()==n*2){
            res.push_back(s);
            return;
        }
        if(x<n){
            s+='(';
            solve(x+1,y,n,s,res);
            s.pop_back();
        }
        if(y<x){
            s+=')';
            solve(x,y+1,n,s,res);
            s.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        string s="";
        vector<string> res;
        //int x=n;
        //int y=n;
        solve(0,0,n,s,res);
        return res;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends
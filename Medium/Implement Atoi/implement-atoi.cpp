//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int n=s.size();
        string s1="";
        int n1;
        if(s[0]=='-'){
            for(int i=1;i<n;i++){
                if(s[i]<'0' or s[i]>'9')
                return -1;
                s1+=s[i];
            }
            n1=stoi(s1);
            n1=-n1;
        }
        else{
            for(int i=0;i<n;i++){
                if(s[i]<'0' or s[i]>'9')
                return -1;
            }
            n1=stoi(s);
        }
        return n1;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends
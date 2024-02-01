//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        string s1="abcdefghijklmnopqrstuvwxyz";
        string s2="";
        int n=s.size();
        if(n<26)
        return false;
        map<char,int> mpp;
        for(int i=0;i<n;i++){
            if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z')){
                mpp[tolower(s[i])]++;
            }
        }
        return mpp.size()==26;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int c_e=0,c_o=0;
	    int n=s.size();
	    for(int i=0;i<n;i++){
	        if(s[i]=='1' and i%2==0)
	        c_e++;
	        else if(s[i]=='1' and i%2!=0)
	        c_o++;
	    }
	    if(abs(c_e-c_o)%3==0)
	    return 1;
	    return 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends
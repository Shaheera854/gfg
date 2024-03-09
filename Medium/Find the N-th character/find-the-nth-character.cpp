//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
  
class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        int x=pow(2,r);
        int ind=-1;
        for(int i=0;i<s.size();i++){
            if((x*(i+1))>=n+1){
                ind=i;
                break;
            }
        }
        string s2="";
        s2+=s[ind];
        while(r--){
            string s1="";
            for(int i=0;i<s2.size();i++){
                if(s2[i]=='1'){
                    s1+="10";
                }
                else{
                    s1+="01";
                }
            }
            s2=s1;
        }
        //cout<<s2<<endl;
        int y=x-((x*(ind+1))-n);
        //cout<<y<<endl;
        return s2[y];
    }
}; 

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends
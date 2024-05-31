//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        string s="";
        string s1;
        for(int i=7;i>=0;i--){
            if(s.size()==4){
                s1=s;
                s="";
            }
            if((n&(1<<i))){
                s+='1';
            }
            else
            s+='0';
        }
        s+=s1;
        //cout<<s1<<" "<<s<<endl;
        int num=0;
        for(int i=0;i<8;i++){
            if(s[i]=='1'){
                num+=(1<<(7-i));
            }
        }
        return num;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
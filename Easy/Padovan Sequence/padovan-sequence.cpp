//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int padovanSequence(int n) {
        // code here.
        int a=1,b=1,c=1;
        int d;
        if(n==0 or n==1 or n==2)
        return 1;
        for(int i=0;i<n-2;i++){
            d=(b%1000000007+a%1000000007)%1000000007;
            a=b;
            b=c;
            c=d;
        }
        return d%1000000007;
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
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
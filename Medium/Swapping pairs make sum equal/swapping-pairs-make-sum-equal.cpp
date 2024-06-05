//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        sort(a,a+n);
        sort(b,b+m);
        int s1=0,s2=0;
        for(int i=0;i<n;i++)
        s1+=a[i];
        for(int i=0;i<m;i++)
        s2+=b[i];
        if(abs(s1-s2)%2)
        return -1;
        int d=abs(s1-s2)/2;
        //int l=0,h=m;
        for(int i=0;i<n;i++){
            if(binary_search(b,b+m,a[i]+d) or binary_search(b,b+m,a[i]-d))
            return 1;
        }
        return -1;
    }
    
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
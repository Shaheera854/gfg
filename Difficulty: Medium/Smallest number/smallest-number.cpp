//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        if(9*d < s)
        return "-1";
        string res = "";
        while(d){
            if(s <= 10){
                if(d == 1)
                {
                    res += to_string(s);
                    s = 0;
                    d = 0;
                    break;
                }
                res += to_string(s-1);
                break;
            }
            else{
                res += '9';
                s -= 9;
            }
            d--;
        }
        while(d-- > 2){
            res += '0';
        }
        if(d > 0)
        res += '1';
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends
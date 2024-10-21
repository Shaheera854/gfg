//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int mod = 1e9+7;
    int countgroup(vector<int>& arr) {
        // Complete the function
        int xor_val = 0;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            xor_val ^= arr[i];
        }
        if(xor_val)
        return 0;
        return int(int(pow(2,n-1)-1)%mod);
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends
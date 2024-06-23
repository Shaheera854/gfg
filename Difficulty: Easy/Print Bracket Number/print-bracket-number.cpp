//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        stack<pair<char,int>> st;
        vector<int> res;
        int k = 1;
        int n = str.size();
        for(int i = 0 ; i < n ; i++){
            if(str[i] == '('){
                res.push_back(k);
                st.push({'(',k});
                k++;
            }
            else if(str[i] == ')'){
                res.push_back(st.top().second);
                st.pop();
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
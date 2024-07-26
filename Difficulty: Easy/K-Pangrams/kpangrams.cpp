//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool kPangram(string str, int k) {
        // code here
        str.erase(remove(str.begin(),str.end(),' '),str.end());
        // cout<<str<<" ";
        int n = str.size();
        if(n < 26) return false;
        vector<int> v(26,0);
        int c = 0;
        for(int i = 0 ; i < n ; i++){
            if(str[i]>='a' and str[i]<='z' and v[str[i]-'a'] == 0){
                c++;
            }
            v[str[i]-'a']++;
        }
        return (c+k >= 26);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
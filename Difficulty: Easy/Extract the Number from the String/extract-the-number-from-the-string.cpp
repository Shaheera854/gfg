//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {
        // code here
        long long maxi = -1;
        int n = sentence.size();
        long long num = 0;
        int i = 0, fl = 0;
        while(i < n){
            if(sentence[i]>='0' and sentence[i]<'9'){
                if(sentence[i] =='0')
                fl = 1;
                num = num*10 + ((long long)sentence[i] - '0');
                i++;
            }
            else if(sentence[i]=='9'){
                num = 0;
                fl = 0;
                while(sentence[i]>='0' and sentence[i]<='9')
                i++;
            }
            else{
                if(num or (num == 0 and fl == 1))
                maxi = max(maxi,num);
                fl = 0;
                num = 0;
                i++;
            }
        }
        if(num or (num == 0 and fl == 1))
        maxi = max(maxi,num);
        return maxi;
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
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends
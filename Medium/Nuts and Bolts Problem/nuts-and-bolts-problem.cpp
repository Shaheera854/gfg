//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        vector<char> arr={'!','#','$','%','&','*','?','@','^'};
        map<char,int> mp1;
        for(int i=0;i<n;i++){
            mp1[nuts[i]]++;
        }
        map<char,int> mp2;
        for(int i=0;i<n;i++){
            mp2[bolts[i]]++;
        }
        int k1=0;
        int k2=0;
        for(int i=0;i<9;i++){
            if(mp1.find(arr[i])!=mp1.end()){
                while(mp1[arr[i]]--){
                    nuts[k1++]=arr[i];
                }
            }
            if(mp2.find(arr[i])!=mp2.end()){
                while(mp2[arr[i]]--){
                    bolts[k2++]=arr[i];
                }
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
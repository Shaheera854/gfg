//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool check(int mid, int k, vector<int>& stalls){
        int total = 1;
        int lp = stalls[0];
        for(int i = 1; i < stalls.size();i++){
            if(stalls[i] - lp >= mid){
                total++;
                lp = stalls[i];
            }
            if(total == k)
            return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int l = 1 , h = (stalls.back() - stalls[0]) / (k-1);
        int ans=0;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(mid,k,stalls)){
                ans = mid;
                l = mid +1;
            }
            else{
                h = mid -1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
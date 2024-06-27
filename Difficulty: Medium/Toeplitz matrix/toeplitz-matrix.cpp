//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToeplitz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


bool isToeplitz(vector<vector<int>>& mat) {
    // code here
    int n = mat.size();
    int m = mat[0].size();
    int j = 1;
    for(int k = 1 ; k < m ; k++){
        int i = 1;
        int temp = j;
        while(i < n and temp < m){
            if(mat[i][temp] != mat[i-1][temp-1])
            return false;
            i++;
            temp++;
        }
        j++;
    }
    int i = 2;
    for(int k = 2 ; k < n ; k++){
        j = 1;
        int temp = i;
        while(temp < n and j < m){
            if(mat[temp][j] != mat[temp-1][j-1])
            return false;
            temp++;
            j++;
        }
        i++;
    }
    
    return true;
}
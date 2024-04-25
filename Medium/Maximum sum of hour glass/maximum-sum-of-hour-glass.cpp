//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        int maxHourglassSum = INT_MIN; // Initialize the maximum sum to the smallest possible integer value

        // Iterate through each cell of the matrix
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                // Calculate the sum of the current hourglass
                int hourglassSum = mat[i][j] + mat[i][j + 1] + mat[i][j + 2] +
                                   mat[i + 1][j + 1] +
                                   mat[i + 2][j] + mat[i + 2][j + 1] + mat[i + 2][j + 2];

                // Update the maximum sum if the current hourglass sum is greater
                maxHourglassSum = max(maxHourglassSum, hourglassSum);
            }
        }

        // If no hourglass is found, return -1
        if (maxHourglassSum == INT_MIN) {
            return -1;
        }

        // Return the maximum hourglass sum
        return maxHourglassSum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends
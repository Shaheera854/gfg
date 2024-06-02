//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        // code here
        vector<int>list;
        int xorVal = 0;
        // traversing in reverse order to minimize the number of xor operations in the array
        // since the element of the array which is not present in the constructed list needs not be xorred
        // try brainstorming for the test case q = 5 , queries = {0, 6}, {1, 3}, {0, 2}, {1, 4}, {0, 5}}
        for(int i = q - 1; i >= 0 ; i--){
            if(queries[i][0] == 0)
                list.push_back(queries[i][1] ^ xorVal); // xorring the added elements with the updated xor value
            else
                xorVal ^= queries[i][1];  // for evaluating the updated value used to xor with the complete array
        }
        list.push_back(0 ^ xorVal); // first element of the list to be constructed
        sort(list.begin(), list.end());
        return list;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int q;
        scanf("%d", &q);

        vector<vector<int>> queries(q, vector<int>(2));
        Matrix::input(queries, q, 2);

        Solution obj;
        vector<int> res = obj.constructList(q, queries);

        Array::print(res);
    }
}

// } Driver Code Ends
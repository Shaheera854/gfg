//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int l,int h, int key, vector<int>& arr){
        if(l > h){
            // cout<<l<<" "<<h<<endl;
            return -1;
        }
        int mid = l + (h-l)/2;
        // cout<<arr[mid]<<" ";
        if(arr[mid] == key){
            // cout<<mid<<" ";
            return mid;
        }
        int ans;
        if(arr[l] <= arr[mid]){
            if(arr[l] <= key and key < arr[mid]){
                ans = solve(l,mid-1,key,arr);
            }
            else{
                ans = solve(mid+1,h,key,arr);
            }
        }
        else{
            if(arr[mid] < key and key <= arr[h]){
                ans = solve(mid+1,h,key,arr);
            }
            else{
                ans = solve(l,mid-1,key,arr);
            }
        }
        return ans;
    }
    int search(vector<int>& arr, int key) {
        // complete the function here
        int n = arr.size();
        return solve(0,n-1,key,arr);
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends
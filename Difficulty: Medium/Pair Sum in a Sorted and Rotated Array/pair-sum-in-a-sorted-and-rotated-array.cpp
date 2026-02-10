// User function Template for C++

class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int max_ind = n-1;
        int min_ind = 0;
        for(int i = 0 ; i < n-1 ; i++){
            if(arr[i] > arr[i+1]){
                max_ind = i;
                min_ind = i+1;
                break;
            }
        }
        int i = min_ind;
        int j = max_ind;
        while(i != j){
            int sum = arr[i]+arr[j];
            if(sum == target){
                return true;
            }
            else if(sum > target){
                j = (j-1+n)%n;
            }
            else{
                i = (i+1)%n;
            }
        }
        return false;
    }
};

// 7 9 1 3 5
// 
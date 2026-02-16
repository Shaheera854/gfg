// User function template for C++
class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // Complete the function
        map<int,int> mpp;
        int n = arr.size();
        int sum = 0, res = 0;
        for(int i = 0 ; i < n ; i++){
            sum = ((sum+arr[i])%k + k)%k;
            if(sum == 0){
                res = i+1;
            }
            else if(mpp.find(sum) != mpp.end()){
                res = max(res, i-mpp[sum]);
            }
            else
            mpp[sum] = i;
        }
        return res;
    }
};
// -10%6 = 4
// 7 -1 2 -2 -9 0 -4 -3 0 -9
// 

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        res.push_back(arr[0]);
        int i = 1;
        while(i < n){
            if(arr[i][0] <= res.back()[1]){
                res.back()[1] = max(res.back()[1],arr[i][1]);
            }
            else{
                res.push_back(arr[i]);
            }
            i++;
        }
        return res;
    }
};
// 1 4 5 6
// 3 7 9 8
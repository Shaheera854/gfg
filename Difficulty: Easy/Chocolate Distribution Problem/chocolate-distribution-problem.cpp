class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(),a.end());
        int n = a.size();
        int mini = INT_MAX;
        for(int i = 0 ; i < n-m+1 ; i++){
            mini = min(mini,a[i+m-1]-a[i]);
        }
        return mini;
    }
};


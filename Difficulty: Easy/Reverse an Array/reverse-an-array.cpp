class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        for(int i = 0 ; i < arr.size()/2 ; i++){
            int temp = arr[i];
            arr[i] = arr[arr.size()-i-1];
            arr[arr.size()-i-1] = temp;
        }
    }
};
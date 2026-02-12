class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        string res = "";
        sort(arr.begin(), arr.end(), [](int a, int b){
            string s1 = to_string(a);
            string s2 = to_string(b);
            return s1+s2 > s2+s1;
        });
        if(arr[0] == 0) return "0";
        for(int i:arr){
            res += to_string(i);
        }
        return res;
    }
};

// 9
// 5
// 3
// 30
// 34
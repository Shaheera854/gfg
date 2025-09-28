class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        multiset<int> s;
        int maxlen = 0;
        int startInd = -1, endInd = -1;
        int i = 0,j = 0;
        s.insert(arr[0]);
        while(j < n)
        {
            int a = *s.begin();
            int b = *s.rbegin();
            if(b-a <= x)
            {
                if(j-i+1 > maxlen)
                {
                    maxlen = j-i+1;
                    startInd = i;
                    endInd = j;
                }
                j++;
                if(j < n)
                    s.insert(arr[j]);
            }
            else
            {
                s.erase(s.find(arr[i]));
                i++;
            }
        }
        vector<int> ans;
        for(int i=startInd; i<=endInd; i++)
            ans.push_back(arr[i]);
        return ans;
    }
};


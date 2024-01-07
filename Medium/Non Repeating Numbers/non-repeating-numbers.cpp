//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int r=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            r^=nums[i];
        }
        int pos=0;
        for(int i=0;i<32;i++){
            if((r&(1<<i))){
                pos=i;
                break;
            }
        }
        int b0=0,b1=0;
        for(int i=0;i<n;i++){
            if((nums[i]&(1<<pos)))
            b1^=nums[i];
            else
            b0^=nums[i];
        }
        return {min(b1,b0),max(b1,b0)};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
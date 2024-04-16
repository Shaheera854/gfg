//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        vector<pair<int,int>> prefix;
        vector<pair<int,int>> suffix;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n-k;i++){
            mini=min(mini,arr[i]);
            maxi=max(maxi,arr[i]);
            prefix.push_back({mini,maxi});
        }
        mini=INT_MAX;
        maxi=INT_MIN;
        for(int i=n-1;i>=k;i--){
            mini=min(mini,arr[i]);
            maxi=max(maxi,arr[i]);
            suffix.push_back({mini,maxi});
        }
        reverse(suffix.begin(),suffix.end());
        int size=prefix.size();
        int mindiff=min(prefix[size-1].second-prefix[size-1].first,suffix[0].second-suffix[0].first);
        for(int i=1;i<size;i++){
            mini=min(suffix[i].first,prefix[i-1].first);
            maxi=max(suffix[i].second,prefix[i-1].second);
            mindiff=min(mindiff,maxi-mini);
        }
        return mindiff;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
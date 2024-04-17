//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    void merge(vector<int> &v,int l,int m,int h,int &c){
        int i=l;
        int j=m+1;
        vector<int> arr1(h-l+1);
        int k=0;
        while(i<=m and j<=h){
            if(v[i]>v[j]){
                c+=(m-i+1);
                arr1[k++]=v[j++];
            }
            else{
                arr1[k++]=v[i++];
            }
        }
        while(i<=m){
            arr1[k++]=v[i++];
        }
        while(j<=h){
            arr1[k++]=v[j++];
        }
        k=0;
        for(int i=l;i<=h;i++){
            v[i]=arr1[k++];
        }
    }
    void mergesort(vector<int> &v,int low,int high,int &c){
        if(low<high){
            int mid=(low+high)/2;
            mergesort(v,low,mid,c);
            mergesort(v,mid+1,high,c);
            merge(v,low,mid,high,c);
        }
    }
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here   
        int cnt=0;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i]=arr[i]*i;
        }
        int c=0;
        mergesort(v,0,n-1,c);
        return c;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    int prefix[n];
	    prefix[0]=arr[0];
	    int max_size=0;
	    if(arr[0]%k==0)
	    max_size=1;
	    for(int i=1;i<n;i++){
	        prefix[i]=arr[i]+prefix[i-1];
	        if(prefix[i]%k==0){
	            max_size=i+1;
	        }
	    }
	    if(prefix[n-1]%k==0)
	    return n;
	    int i=0;
	    int size=n;
	    while(size){
	        if(i+size-1>=n){
	            i=0;
	            size--;
	        }
	        if(max_size<size && (prefix[i+size-1]-prefix[i])%k==0)
	        return size-1;
	        i++;
	    }
	    return max_size;
	}
};//2 9 15 16 20 25
  //0 1  2  3  4  5

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends
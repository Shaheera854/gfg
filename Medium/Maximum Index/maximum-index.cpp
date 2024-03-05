//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        // Your code here
        int minarr[n];
        int maxarr[n];
        minarr[0]=arr[0];
        for(int i=1;i<n;i++){
            minarr[i]=min(arr[i],minarr[i-1]);
        }
        maxarr[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            maxarr[i]=max(arr[i],maxarr[i+1]);
        }
        int i=0,j=0,maxi=0;
        while(i<n and j<n){
            if(minarr[i]<=maxarr[j]){
                maxi=max(maxi,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return maxi;
    } 
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends
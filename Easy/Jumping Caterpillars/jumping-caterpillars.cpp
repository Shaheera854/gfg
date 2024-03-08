//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int uneatenLeaves(int arr[],int n,int k);


int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
         
        int n;
        cin>>n;
        int k;
        cin>>k;
        int arr[k];
        for(int i=0;i<k;i++)
        cin>>arr[i];
        cout<<uneatenLeaves(arr,n,k)<<endl;
    }
 }
    
        
// } Driver Code Ends

int uneatenLeaves(int arr[],int n,int k)
{
    // Your code goes here   
    unordered_map<int,bool> mpp;
    sort(arr,arr+k);
    for(int i=0;i<k;i++){
        if(!mpp[arr[i]]){
            for(int x=1;arr[i]*x<=n;x++){
                mpp[arr[i]*x]=true;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!mpp[i])
        cnt++;
    }
    return cnt;
}

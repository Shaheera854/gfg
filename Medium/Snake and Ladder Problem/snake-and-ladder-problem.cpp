//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        map<int,int> mpp;
        for(int i=0;i<N*2;i+=2){
            mpp[arr[i]]=arr[i+1];
        }
        queue<int> q;
        q.push(1);
        int c=0;
        vector<int> vis(30,0);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int temp=q.front();
                q.pop();
                for(int i=1;i<=6;i++){
                    int x=temp+i;
                    if(mpp.find(x)!=mpp.end() and mpp[x]==30)
                    return c;
                    if(x==30){
                        return c+1;
                    }
                    if(mpp.find(x)!=mpp.end()){
                        if(mpp[x]>x and !vis[mpp[x]]){
                            q.push(mpp[x]);
                            vis[mpp[x]]=1;
                        }
                    }
                    else{
                        q.push(x);
                        vis[x]=1;
                    }
                }
            }
            c++;
        }
        return c;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
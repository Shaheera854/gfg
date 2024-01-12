//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

vector<int> primes(1e6+1,1);
class Solution
{
    public:
    void Generate(vector<int> &primes){
    	primes[0]=0;
    	primes[1]=0;
    	if(primes[4] == 0) return;
    	int n=1e6+1;
    	for(int i=2;i*i<=n;i++){
    		if(primes[i]){
    			for(int j=i*i;j<n;j+=i){
    				primes[j]=0;
    			}
    		}
    	}
    }
    int minNumber(int arr[],int N)
    {
        Generate(primes);
        int s=0;
        for(int i=0;i<N;i++){
            s+=arr[i];
        }
        int temp=s;
        while(!primes[temp])
        temp++;
        return temp-s;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
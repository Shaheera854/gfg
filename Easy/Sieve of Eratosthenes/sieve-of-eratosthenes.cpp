//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void GeneratePrime(vector<int> &primes){
    	primes[0]=0;
    	primes[1]=0;
    	int n=primes.size();
    	for(int i=2;i*i<=n;i++){
    		if(primes[i]){
    			for(int j=i*i;j<n;j+=i){
    				primes[j]=0;
    			}
    		}
    	}
    	
    }
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        vector<int> primes(N+1,1);
        GeneratePrime(primes);
        vector<int> res;
        for(int i=2;i<=N;i++){
            if(primes[i])
            res.push_back(i);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    void Gen_primes(vector<int> &primes,int n){
        // if(primes[4]==0)
        // return;
        primes[0]=0;
        primes[1]=0;
        //int n=1e6+1;
        for(int i=2;i*i<=n;i++){
            if(primes[i]){
                for(int j=i*i;j<=n;j+=i){
                    primes[j]=0;
                }
            }
        }
    }
    vector<int> getPrimes(int n) {
        // code here
        vector<int> primes(n+1,1);
        Gen_primes(primes,n);
        if(n%2!=0){
            if(primes[n-2])
            return {2,n-2};
            return {-1,-1};
        }
        if(n==4)
        return {2,2};
        // for(int i=0;i<=20;i++)
        // cout<<i<<" "<<primes[i]<<endl;
        for(int i=3;i<=n/2;i+=2){
            if(primes[i]!=0 and primes[n-i]!=0){
                return {i,n-i};
            }
        }
        return {-1,-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends
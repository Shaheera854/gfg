//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	    int i1=0,j1=0,i2=n-1,j2=n-1,cnt=0;
	    while(i1<n and i2>=0){
	        while(j1<n and j2>=0){
	            int s=mat1[i1][j1]+mat2[i2][j2];
	            if(s==x){
	                //cout<<mat1[i1][j1]<<" "<<mat2[i2][j2]<<endl;
	                cnt++;
	                j1++;
	                j2--;
	            }
	            else if(s<x){
	                j1++;
	            }
	            else{
	                j2--;
	            }
	        }
	        if(j1==n and j2<0){
	            i1++;
	            j1=0;
	            i2--;
	            j2=n-1;
	        }
	        else if(j1==n){
	            i1++;
	            j1=0;
	        }
	        else{
	            i2--;
	            j2=n-1;
	        }
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends
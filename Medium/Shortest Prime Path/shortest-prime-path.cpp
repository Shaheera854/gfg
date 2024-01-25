//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
/*
int n=(temp1%k)/(k/10);
int x=((temp1/k)*10+i)*(k/10)+(temp1%(k/10));
*/
vector<int> primes(10000,1);
void GeneratePrime(vector<int> &primes){
	primes[0]=0;
	primes[1]=0;
	if(primes[4]==0)
	return;
	int n=10000;
	for(int i=2;i*i<=n;i++){
		if(primes[i]){
			for(int j=i*i;j<n;j+=i){
				primes[j]=0;
			}
		}
	}
}
class Solution{   
public:
    
    int solve(int num1,int num2)
    {   
      //code here
      GeneratePrime(primes);
      queue<pair<int,int>> q;
      set<int> vis;
      vis.insert(num1);
      if(num1==num2)
      return 0;
      q.push({num1,0});
      //int k=10;
      //int c=0;
      while(!q.empty()){
          int temp1=q.front().first;
          int temp2=q.front().second;
          //vis.insert(temp1);
          for(int i=1;i<=4;i++){
              for(int j=0;j<10;j++){
                  int k=pow(10,i);
                  int n=(temp1%k)/(k/10);
                  int x=((temp1/k)*10+j)*(k/10)+(temp1%(k/10));
                  int temp=x;
                  int c=0;
                  while(temp){
                      c++;
                      temp/=10;
                  }
                  if(x==num2)
                  return temp2+1; 
                  if(c==4 and n!=j and !vis.count(x) and primes[x]){
                      q.push({x,temp2+1});
                      //cout<<x<<" ";
                      vis.insert(x);
                  }
              }
          }
          q.pop();
      }
      return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends
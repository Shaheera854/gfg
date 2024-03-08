//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    int n=s.size();
	    map<char,int> mp;
	    vector<int> v;
	    for(int i=0;i<n;i++){
	        mp[s[i]]++;
	    }
	    if(mp.size()==1)
	    return true;
	    map<int,int> mp1;
	    for(auto it:mp){
	        mp1[it.second]++;
	    }
	    if(mp1.size()>2)
	    return false;
	    if(mp1.size()==1)
	    return true;
	    auto it2=mp1.begin();
	    it2++;
	    auto it1=mp1.begin();
	    if((it1->first!=1 or it1->second>1) and (it1->first+1!=it2->first or it2->second>1)){
	        //cout<<it1->first<<" "<<it2->first<<endl;
	    return false;
	    }
	    //if(it1->first==1 and it1->second==1)
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends
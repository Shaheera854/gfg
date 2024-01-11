//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    string removeKdigits(string S, int K) {
        stack<int> st;
        st.push(S[0]-'0');
        //cout<<st.top();
        for(int i=1;i<S.size();i++){
            while(!st.empty() and K!=0 and st.top()>(S[i]-'0')){
                st.pop();
                K--;
            }
            st.push(S[i]-'0');
        }
        while(K){
            st.pop();
            K--;
        }
        string res="";
        while(!st.empty()){
            //cout<<st.top()<<" ";
            res+=(to_string(st.top()));
            st.pop();
        }
        //cout<<endl;
        reverse(res.begin(),res.end());
        int i=0;
        while(res[0]=='0'){
            res.erase(res.begin()+0);
        }
        if(res.empty())
        return "0";
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends
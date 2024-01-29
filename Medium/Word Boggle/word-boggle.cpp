//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
vector<int> rp={0,0,-1,-1,-1,1,1,1};
vector<int> cp={-1,1,0,-1,1,0,-1,1};
class Solution {
public:
    bool isValid(int r,int c,int m,int n,set<pair<int,int>> &vis){
        if(r<0 or c<0 or r>=m or c>=n)
        return false;
        if(vis.count({r,c}))
        return false;
        return true;
    }
    void solve(int ind,string s,stack<pair<int,int>> &st,vector<vector<char>> &board,set<pair<int,int>> &vis,vector<string>&res,int &rsize,int &csize,int size,bool &f){
        if(ind==s.size()){
            res.push_back(s);
            f=true;
            return;
        }
        while(!st.empty()){
            auto temp=st.top();
            int row=temp.first;
            int col=temp.second;
            st.pop();
            for(int i=0;i<8;i++){
                int x=row+rp[i];
                int y=col+cp[i];
                if(isValid(x,y,rsize,csize,vis) and board[x][y]==s[ind]){
                    st.push({x,y});
                    vis.insert({x,y});
                    solve(ind+1,s,st,board,vis,res,rsize,csize,size,f);
                    vis.erase({x,y});
                }
                if(f)
                return;
            }
        }
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	     vector<string>res;
	     int n=dictionary.size();
	     int rsize=board.size();
	     int csize=board[0].size();
	     for(int i=0;i<n;i++){
	         set<pair<int,int>> vis;
	         stack<pair<int,int>> st;
	         char ch=dictionary[i][0];
	         bool f=false;
	         int fl=0;
	         for(int j=0;j<rsize;j++){
	             for(int k=0;k<csize;k++){
	                 if(ch==board[j][k]){
	                     st.push({j,k});
	                     vis.insert({j,k});
	                     solve(1,dictionary[i],st,board,vis,res,rsize,csize,1,f);
	                     if(f)
	                     {
	                         fl=1;
	                         break;
	                     }
	                     vis.erase({j,k});
	                 }
	             }
	             if(fl==1)
	             break;
	         }
	     }
	     sort(res.begin(),res.end());
	     return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
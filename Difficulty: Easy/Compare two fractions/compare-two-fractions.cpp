//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {
        // Code here
        int fl = 0, num1 = 0, num2 = 0,num3=0,num4=0, num = 0,ind;
        int n = str.size();
        for(int i = 0 ; i < n ; i++){
            if(str[i] >= '0' and str[i] <= '9'){
                num = num*10 + ((int)str[i] - '0');
            }
            else if(str[i] == '/' and fl == 0){
                num1 = num;
                fl = 1;
                num = 0;
            }
            else if(str[i] ==','){
                num2 = num;
                num = 0;
                ind = i;
            }
            else if(str[i] =='/'){
                num3 = num;
                num = 0;
            }
        }
        num4 = num;
        if(num1*num4 > num2*num3){
            return str.substr(0,ind);
        }
        else if(num1*num4 < num2*num3)
        return str.substr(ind+2,n);
        return "equal";
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string s){
        int  n = s.size();
        int index = 0;
        for(int i = 1; i<n; i++) {
            if(s[0] == s[1]) break;
            if(s[i] <= s[i-1]) {
                index = i;
            }
            else break;
        }
        string t  = s.substr(0, index+1);
        string p = t;
        reverse(p.begin(), p.end());
        return t+p;
        // Code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends
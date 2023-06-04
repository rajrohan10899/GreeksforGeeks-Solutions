//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            s = '*'+ s;
            reverse(s.begin(), s.end());
            int prev = 0;
            for(int i=0; i<s.length(); i++) {
                if(s[i]=='*' || s[i] =='+' || s[i] == '-' || s[i] == '/') {
                    reverse(s.begin()+prev, s.begin()+i);
                    prev = i+1;
                }
            }
            return s.substr(0, s.length()-1);
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string str) 
    { 
        // code here 
    reverse(str.begin(), str.end());
     int start = 0;
     for(int i = 0; i<str.size(); i++) {
         if(str[i] == '.') {
             reverse(str.begin()+start, str.begin() +i);
             start = i+1;
         }
     }
     reverse(str.begin() + start, str.end());
     return str;
     
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
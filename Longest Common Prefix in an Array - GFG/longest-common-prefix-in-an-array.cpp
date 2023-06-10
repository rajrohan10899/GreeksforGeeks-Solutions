//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string s = arr[0];
        int flag = 0;
        for(int i=1;i<N;i++){
            string s1 = "";
            int j=0;
            while(arr[i][j]==s[j] && s[j]!='\0' && arr[i][j]!='\0')
                s1+=s[j++];
            s = s1;
        }
        if(s == "") return "-1";
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
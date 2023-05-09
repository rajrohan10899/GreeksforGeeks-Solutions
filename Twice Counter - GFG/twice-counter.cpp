//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        int countWords(string list[], int n)
        {
           //code here.
           map<string, int> mpp;
           int ans = 0;
           for(int i = 0; i<n; i++) {
               mpp[list[i]]++;
           }
             for(auto it : mpp) {
                   if(it.second == 2) {
                       ans++;
                   }
               }
               return ans;
           }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string list[n];
        for(int i=0;i<n;i++)
            cin>>list[i];
        Solution ob;    
        cout <<ob.countWords(list, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
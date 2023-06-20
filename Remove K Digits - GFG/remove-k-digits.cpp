//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string num, int k) {
        
        string ans = "";

        for(int i=0; i<num.size(); i++)
        {
            while(!ans.empty() && ans.back() > num[i] && k > 0)
            {
                ans.pop_back();
                k--;
            }
            ans.push_back(num[i]);
        }
        while(k--)
        {
            ans.pop_back();
        }
        //Comparing Front if encountered "0" earse it.

        while(ans.front() == '0')
        {
            ans.erase(ans.begin());
        }
        if(ans.empty())
            return "0";
        
       return ans;   
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
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        string ans = "";
        
        // Check if it's impossible to create a number with N digits and sum S
        if (S == 0 && N > 1) {
            return "-1";
        }
        
        // Fill the number from left to right with the largest possible digits
        for (int i = 0; i < N; i++) {
            if (S > 9) {
                ans += '9';
                S -= 9;
            } else {
                ans += to_string(S);
                S = 0;
            }
        }
        
        // If there's a remainder, it's not possible to create the number
        if (S != 0) {
            return "-1";
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
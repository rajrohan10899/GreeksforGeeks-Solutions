//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends

// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // Approach : nCr = n-1Cr-1 + n-1Cr
        // store nCr in table with n+1 rows and start with col 1 then go on increasing till n+1
        // here n=4 so if we look closely it is basically 3C0 3C1 3C2 3C3
        // so we will req table of 4 rows    
        vector<vector<ll>> table(n);
        int mod = 1e9+7;
        for(int i=0; i<n; i++)
        {
            table[i] = vector<ll> (i+1, 1);
            for(int j=1; j<i; j++)
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) %mod;
        }
        
        return table[n-1];
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends
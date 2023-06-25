//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// User function template for C++

class Solution {
  public:
    int check(int n, int d, int sum){
        if(n == 0) return 1;
        if(n%10==d) return 0;
        if(sum!=0 && sum >= n%10) return 0;
        return check(n/10,d,sum+(n%10));
    }
    vector<int> goodNumbers(int L, int R, int D) {
        vector<int> ans;
        for(int i = L; i <= R; i++){
            if(i%100!=0)
            if(check(i,D,0))
            ans.push_back(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends
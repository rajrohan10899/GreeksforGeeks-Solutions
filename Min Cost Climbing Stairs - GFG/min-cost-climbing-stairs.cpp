//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int helper(int idx, vector<int> &cost, vector<int> &dp) {

        if(idx >= cost.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int one_Jump = cost[idx] + helper(idx+1, cost, dp);
        
        int two_Jump = cost[idx] + helper(idx+2, cost, dp);

        return dp[idx] = min(one_Jump, two_Jump);
        
    }
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        vector<int>dp(N+1, -1);

        return min(helper(0, cost, dp), helper(1, cost, dp));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
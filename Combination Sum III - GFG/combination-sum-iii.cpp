//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void func(int idx, int sum, int n, vector<vector<int>>& ans, vector<int>& ds, int k) {
        if (sum == n && ds.size() == k) {
            ans.push_back(ds);
            return;
        }
        if (sum > n || ds.size() > k) {
            return;
        }
        for (int i = idx; i <= 9; i++) {
            if (sum + i > n) {
                break;
            }
            ds.push_back(i);
            func(i + 1, sum + i, n, ans, ds, k);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum(int k, int n) {
        // code here
        vector<int> ds;
        vector<vector<int>> ans;
        func(1, 0, n, ans, ds, k);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
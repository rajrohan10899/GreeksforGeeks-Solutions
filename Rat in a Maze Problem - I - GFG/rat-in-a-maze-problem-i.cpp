//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(int i, int j, vector<vector<int>>& a, int n, vector<string>& ans, string move, vector<vector<int>>& vis, int di[], int dj[]) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }
        string dir = "DLRU";
        for (int idx = 0; idx < 4; idx++) {
            int nexti = i + di[idx];
            int nextj = j + dj[idx];

            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
                vis[nexti][nextj] = 1;  // Fix: Update the visited array for the next cell
                solve(nexti, nextj, a, n, ans, move + dir[idx], vis, di, dj);
                vis[nexti][nextj] = 0;  // Fix: Reset the visited array after backtracking
            }
        }
    }  
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
         vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int di[] = { 1, 0, 0, -1 };
        int dj[] = { 0, -1, 1, 0 };
        
        if (m[0][0] == 1) {
            vis[0][0] = 1;  // Fix: Mark the starting cell as visited
            solve(0, 0, m, n, ans, "", vis, di, dj);
        }
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
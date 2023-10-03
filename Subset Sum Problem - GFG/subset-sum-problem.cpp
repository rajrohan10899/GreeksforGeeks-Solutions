//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(int idx, vector<int> &arr, int sum, vector<vector<int>> &dp) {
         
        if (sum == 0) return true;
        
        if(idx == 0) return (arr[0] == sum);
        
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        bool notPick = solve(idx-1, arr, sum, dp);
        
        bool pick = false;
        
        if(arr[idx <= sum]) {
            pick = solve(idx-1, arr, sum-arr[idx], dp);
        }
        return dp[idx][sum] = notPick || pick;
    }
    bool isSubsetSum(vector<int>arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return solve(n-1, arr, sum, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int>>& matrix, int n)
    {
        vector<int> rowSum(n, 0); // Initialize rowSum vector with zeros
        vector<int> colSum(n, 0); // Initialize colSum vector with zeros
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i] += matrix[i][j]; // Update rowSum for each row
                colSum[j] += matrix[i][j]; // Update colSum for each column
            }
        }
        
        int maxSum = 0;
        for (int i = 0; i < n; i++) {
            maxSum = max(maxSum, max(rowSum[i], colSum[i]));
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (maxSum - rowSum[i]); // Add the difference to ans for each row
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends
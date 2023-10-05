//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int arr[], int N, int totSum) {
        if (N == 0 && totSum != 0) {
            return 0;
        }

        if (totSum == 0) {
            return 1;
        }

        if (arr[N - 1] <= totSum) {
            return solve(arr, N - 1, totSum - arr[N - 1]) || solve(arr, N - 1, totSum);
        } else {
            return solve(arr, N - 1, totSum);
        }
    }

    int equalPartition(int N, int arr[]) {
        int totSum = 0;
        for (int i = 0; i < N; i++) {
            totSum += arr[i];
        }

        if (totSum % 2 != 0)
            return 0;

        return solve(arr, N, totSum / 2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
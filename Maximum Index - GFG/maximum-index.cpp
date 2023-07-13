//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        vector<int>mini(N);
        vector<int>maxi(N);
        
        mini[0]=A[0];
        maxi[N-1]=A[N-1];
        
        for(int i=1;i<N;i++){
            mini[i]=min(mini[i-1],A[i]);
            maxi[N-i-1]=max(maxi[N-i],A[N-i-1]);
        }
        
        int ans=0;
        int i=0;
        int j=0;
        
        while(i<N&&j<N){
            if(mini[i]<=maxi[j]){
                ans=max(ans,j-i);
                j++;
            }
            
            else{
                i++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
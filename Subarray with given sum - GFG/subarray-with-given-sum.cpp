//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        long long smm = 0;
        
        int l = 0, r = 0;
        if(s == 0) return {-1};
        
        while(r < n) {
            while(r<n && smm < s) {
                smm += arr[r];
                r++;
            }
            
            while(l<=r && smm > s) {
                smm -= arr[l];
                l++;
            }
            if(l > r) {
                smm = 0; r = l;
            }
            if(smm == s) return {l+1, r};
        }
        
        return {-1};
        
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
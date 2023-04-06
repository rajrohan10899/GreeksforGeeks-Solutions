//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<long long,int>m;
        int maxlen=0;
        long long sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            if(sum==K)
            {
                maxlen=max(maxlen,i+1);
            }
            long long rem=sum-K;
            if(m.find(rem)!=m.end())
            {
                int len=i-m[rem];
                maxlen=max(len,maxlen);
            }
            if(m.find(sum)==m.end())
            {
                m[sum]=i;
            }
        }
        return maxlen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
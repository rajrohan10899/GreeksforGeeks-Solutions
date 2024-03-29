//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthStair(int n){
		    //  Code here
		    if(n < 0) return 0;
		    
		    if(n <= 1) return 1;
		    
		    int totalways = nthStair(1) + nthStair(n-2);
		    
		    return totalways;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        int n = s.length();
    int ans = 0;
    vector<int> vec(128, -1);
    for (int i = 0, j = 0; j < n; j++) {
        i = max(i, vec[s[j]] + 1);
        ans = max(ans, j - i + 1);
        vec[s[j]] = j;
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
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void solve(vector<int> &nums, int left, int right, vector<int> &res) {
        if (left > right) return;

        int middle = (left + right) / 2;

        res.push_back(nums[middle]);

        solve(nums, left, middle - 1, res);
        solve(nums, middle + 1, right, res);
    }

    vector<int> sortedArrayToBST(vector<int> &nums) {
        vector<int> res;
        solve(nums, 0, nums.size() - 1, res);
        return res;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
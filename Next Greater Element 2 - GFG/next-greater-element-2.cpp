//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& nums) {
        // code here
        vector<int> ans(nums.size(), -1);
        stack<int> st;

        for(int i=0; i<2 * nums.size(); i++)
        {
            int num = nums[i % nums.size()];

            while(!st.empty() && nums[st.top()] < num)
            {
                ans[st.top()] = num;
                st.pop();
            }
            if(i < nums.size())
                 st.push(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
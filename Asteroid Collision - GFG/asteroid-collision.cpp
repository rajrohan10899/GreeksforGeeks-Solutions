//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteriod) {
        // code here
        stack<int> st;

        for(int i = 0; i<asteriod.size(); i++)
        {
            //stack is empty or asteriod[i]"positive".
            if(st.empty() ||asteriod[i] > 0)
            {
                st.push(asteriod[i]);
            }
            //asteriod[i] = negative.
            else{
                while(true)
                {
                    int top = st.top();
                    if(top < 0)
                    {
                        st.push(asteriod[i]);
                        break;
                    }
                    else if(top == -asteriod[i])
                    {
                        st.pop();
                        break;
                    }
                    else if(top > (-asteriod[i]))
                    {
                        break;
                    }
                    else {
                        st.pop();
                        if(st.empty())
                        {
                            st.push(asteriod[i]);
                            break;
                        }
                    }
                }
            }
        }
        vector<int> ans(st.size(),0);
        for(int i = st.size()-1; i>=0; i--)
        {
            ans[i] = st.top();
            st.pop();
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

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
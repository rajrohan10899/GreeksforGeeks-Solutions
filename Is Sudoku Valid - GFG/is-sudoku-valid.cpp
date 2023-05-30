//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isvalid(vector<vector<int>>& mat, int sr, int er, int sc, int ec) {
        unordered_set<char> st;

        for (int i = sr; i <= er; i++) {
            for (int j = sc; j <= ec; j++) {
                if (mat[i][j] == 0)
                    continue;

                if (st.find(mat[i][j]) != st.end())
                    return 0;

                st.insert(mat[i][j]);
            }
        }
        return 1;
    }

    int isValid(vector<vector<int>>& mat) {
        // validate rows:
        for (int row = 0; row < 9; row++) {
            unordered_set<char> st;
            for (int col = 0; col < 9; col++) {
                if (mat[row][col] == 0)
                    continue;
                if (st.find(mat[row][col]) != st.end())
                    return 0;
                st.insert(mat[row][col]);
            }
        }

        // validate columns:
        for (int col = 0; col < 9; col++) {
            unordered_set<char> st;
            for (int row = 0; row < 9; row++) {
                if (mat[row][col] == 0)
                    continue;
                if (st.find(mat[row][col]) != st.end())
                    return 0;
                st.insert(mat[row][col]);
            }
        }

        // validate 3x3 boxes:
        for (int sr = 0; sr < 9; sr += 3) {
            int er = sr + 2;
            for (int sc = 0; sc < 9; sc += 3) {
                int ec = sc + 2;
                if (!isvalid(mat, sr, er, sc, ec))
                    return 0;
            }
        }

        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
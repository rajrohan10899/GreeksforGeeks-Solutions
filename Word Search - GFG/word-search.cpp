//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool find(vector<vector<char>>& board, int i, int j, int idx, string &word) {
        if(idx == word.length()) 
            return true;

        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '*')
            return false;

        if(board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '*';

        for(auto& dir: directions) {
            int di = i + dir[0];
            int dj = j + dir[1];

            if(find(board, di, dj, idx + 1, word))
                return true;
        }

        board[i][j] = temp;
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        m = board.size();
        n = board[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == word[0] && find(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends
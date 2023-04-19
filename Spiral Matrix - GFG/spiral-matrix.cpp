//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        int cnt=0;
        int left=0,right=m-1;
        int top=0,bottom=n-1;
        // int cnt=0;
        
        while(cnt<n*m){
            for(int i=left; i<=right; i++){
                cnt++;
                if(cnt==k){
                    return a[top][i];
                }
            }
            top++;
            
            for(int i=top; i<=bottom; i++){
                cnt++;
                if(cnt==k){
                    return a[i][right];
                }
            }
            right--;
            
            // if(top<=bottom){
                for(int i=right; i>=left; i--){
                    cnt++;
                    if(cnt==k){
                        return a[bottom][i];
                    }
                }
                bottom--;
            // }
            
            // if(left<=right){
                for(int i=bottom; i>=top; i--){
                    cnt++;
                    if(cnt==k){
                        return a[i][left];
                    }
                }
                left++;
            // }
        }
        return -1;
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends
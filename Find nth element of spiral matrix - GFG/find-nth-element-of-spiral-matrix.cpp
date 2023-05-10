//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int findK(int [MAX][MAX],int ,int ,int );
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
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int findK(int matrix[MAX][MAX], int n, int m, int k)
{
//Your code here
 int left = 0, right = m-1;
      int top = 0, bottom = n-1;
      vector<int> ans;

      while(top <= bottom && left <= right) {
        //left to right movement
        for(int i = left; i <= right; i++) {
          ans.push_back(matrix[top][i]);
        }
        top++;
        //top to bottom:
        for(int i = top; i <= bottom; i++) {
          ans.push_back(matrix[i][right]);
        }
        right--;
        if(top <= bottom) {
          for(int i = right; i >= left; i--) {
            ans.push_back(matrix[bottom][i]);
          }
          bottom--;
          if(left <= right) {
            for(int i = bottom; i >= top; i--) {
              ans.push_back(matrix[i][left]);
            }
            left++;
          }
        }
      }
      return ans[k-1];  
}


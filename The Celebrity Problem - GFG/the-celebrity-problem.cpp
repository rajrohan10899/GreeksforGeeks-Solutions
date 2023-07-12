//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    bool knows(vector<vector<int>>& M, int A, int B, int n) {
        if(M[A][B] == 1)
            return true;
        else
            return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        
        //psuh all elements in stack.
        for(int i=0; i<n; i++) {
            st.push(i);
        } 
        
        //Step 2. 
        while(st.size() > 1) {
            
            int A = st.top();
            st.pop();
            
            int B = st.top();
            st.pop();
            
            //3 step for knows and push
            
            if(knows(M, A, B, n)) {
                //A ko discard krdo B ko push krdo.
                st.push(B);
            }
            else {
                //B ko discard krdo a ko push krdo.
                st.push(A);
            }
        }
        //step 4. Single element left in satck so check for its potential to be a celebrity.
        int ans = st.top();
        
        int zeroCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[ans][i] == 0)
                zeroCount++;
        }
        
        //all zeroes
        if(zeroCount != n)
            return -1;
        
        //column check
        int oneCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[i][ans] == 1)
                oneCount++;
        }
        
        if(oneCount != n-1)
            return -1;
        
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
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
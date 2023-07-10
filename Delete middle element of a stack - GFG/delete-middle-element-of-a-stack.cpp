//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    
    void helper(stack<int>&st, int count, int size) {
        
        //Base case
        if(count == size/2) {
            st.pop();
            return;
        }
        
        int num = st.top();
        st.pop();
        
        //Recursive call 
        
        helper(st, count+1, size);
        st.push(num);
    }
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&st, int size)
    {
        // code here.. 
        int count = 0;
        
        helper(st, count, size);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends
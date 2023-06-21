//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        void findMinimumToRight(long long heights[], vector<int>& smallToRight, int n){
        stack<int> s;
        s.push(-1);
        for(int i = n-1 ; i>=0; i--){
            //If found small element

            while(s.top() != -1 && heights[s.top()] >= heights[i]){
                s.pop();
            }

            smallToRight.push_back(s.top());
            s.push(i);
        }
        reverse( smallToRight.begin(), smallToRight.end() );
    }

    void findMinimumToLeft(long long heights[], vector<int>& smallToLeft, int n){

        stack<int> s;
        s.push(-1);

        for(int i=0; i<n; i++){
            while(s.top() != -1 && heights[s.top()] >= heights[i]){
                s.pop();
            }

            smallToLeft.push_back(s.top());
            s.push(i);
        }
        
    }
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<int> smallToLeft;
        vector<int> smallToRight;
        findMinimumToLeft(arr, smallToLeft, n);
        findMinimumToRight(arr, smallToRight, n);
        long long maxArea = INT_MIN, currArea = INT_MIN, width;
        for(int i=0; i<n; i++){
            //Important line in the code
            if(smallToRight[i] == -1){
                smallToRight[i] = n;
            }
            width = smallToRight[i] - smallToLeft[i] - 1;
            currArea = width*arr[i];
            maxArea = max(maxArea, currArea);
        }
        return maxArea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
    vector<int> ans(n, -1); // Initialize the answer vector with -1
    
    for (int i = 0; i < n; i++)
    {
        int nextSmaller = -1; // Variable to store the next smaller element
        
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                nextSmaller = arr[j];
                break;
            }
        }
        
        ans[i] = nextSmaller;
    }
    
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
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends
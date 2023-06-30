//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void func(int idx, int sum, vector<int> &arr, int N, vector<int> &sumSubsets)
    {
        if(idx == N) {
            sumSubsets.push_back(sum);
            return;
    }
    //Pick the element.
    func(idx + 1, sum + arr[idx], arr, N, sumSubsets);
    
    //Donot pick the element.
    func(idx + 1, sum, arr, N, sumSubsets);
    }
    
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> sumSubsets;
        
        func(0, 0, arr, N, sumSubsets);
        
        sort(sumSubsets.begin(), sumSubsets.end());
        
        return sumSubsets;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
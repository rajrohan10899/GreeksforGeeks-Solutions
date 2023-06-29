//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
public:
    void findCombination(int idx, int B, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds)
    {
        if (idx == arr.size()) {
            if (B == 0) {
                ans.push_back(ds);
            }
            return;
        }
        // Picking Up condition.
        if (arr[idx] <= B) {
            ds.push_back(arr[idx]);
            findCombination(idx, B - arr[idx], arr, ans, ds);
            ds.pop_back();
        }
        // Not picking up condition.
        findCombination(idx + 1, B, arr, ans, ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& A, int B) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        findCombination(0, B, A, ans, ds);
        
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends
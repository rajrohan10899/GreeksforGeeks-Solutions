//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int q, vector<int> &indices){
        //write your code here
        vector<int> res;
        
       for(int i = 0; i<q; i++)
       {
           int idx = indices[i];
           int element = arr[idx];
           int count = 0;
           
           for(int j = idx+1; j<n; j++)
           {
               if(element < arr[j])
               {
                   count++;
               }
           }
           res.push_back(count);
       }
       return res;
    }

};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> v1(n);
       for(int i = 0;i<n;i++) cin >> v1[i];
        int q; cin >> q;
        vector<int> v2(q);
        for(int i = 0;i<q;i++) cin >> v2[i];

        Solution obj;
        vector<int> ans = obj.count_NGE(n,v1,q,v2);

        for(int i = 0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
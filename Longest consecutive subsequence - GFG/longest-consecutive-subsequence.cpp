//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int nums[], int N)
    {
      //Your code here
      sort(nums, nums + N);
        
        int longest = 1;    //longest
        int prev = nums[0];    //lastSmaller
        int curr = 1;            //currCount
        
        for(int i = 1;i < N;i++){
            if(nums[i] == prev+1){
                curr++;
            }
            else if(nums[i] != prev){
                curr = 1;
            }
            prev = nums[i];
            longest = max(longest, curr);
        }
        return longest;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends
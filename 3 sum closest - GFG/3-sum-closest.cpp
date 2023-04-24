//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int a[], int N, int X)
    {
        // code here
        int diff=INT_MAX;
        int ans=0;
     sort(a, a+N);
     for(int i=0;i<N-2;i++){
     int low=i+1;
     int high=N-1;
     int first=a[i];
     while(low<high){
         if(first+a[low]+a[high]==X){
             return X;
         }
         else if(abs(first+a[low]+a[high]-X)<diff){
             diff=abs(first+a[low]+a[high]-X);
             ans=first+a[low]+a[high];
         }
         if(first+a[low]+a[high]<X){
             low++; 
         }
        else{ high--;
            }
     }
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
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends
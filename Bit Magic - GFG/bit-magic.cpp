//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int bitMagic(int n, vector<int> &arr) {
        // code here
        int i=0,j=n-1;
        int res=0;
        int k=-1;
        while(i<j)
        {
            if(arr[i]!=arr[j])
            {
                if(k==-1)
                {
                    if(arr[i]==1)
                        k=i;
                    else
                        k=j;
                }
                else
                {
                    if(arr[i]==1)
                    {
                        arr[k]=0;
                        arr[i]=0;
                    }
                    else
                    {
                        arr[k]=0;
                        arr[j]=0;
                    }
                    k=-1;
                    res++;
                }
            }
            i++;
            j--;
        
        }
        if(k!=-1)
            res++;
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.bitMagic(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
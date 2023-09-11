//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution {
public:
    bool isLucky(int n) {
        int current = 2; // Start with the second number (index 1)
        
        for (int i = 2; i <= n; i++) {
            if (n % current == 0) {
                return 0; // If n is divisible by current, it's not lucky
            }
            
            int next = (n - n / current); // Calculate the next number after deletion
            n = next;
            current++;
        }
        
        return 1;
    }
};


//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends
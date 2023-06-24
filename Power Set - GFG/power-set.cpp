//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	   void powerset(int i,vector<string> &v,string str,string s)
	   {
	       if(i==s.length())
	       {
	           v.push_back(str);
	           return;
	       }
	       
	       powerset(i+1,v,str+s[i],s);
	       powerset(i+1,v,str,s);
	       
	   }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int i=0;
		    string str="";
		    vector<string> v;
		    powerset(i,v,str,s);
		    v.pop_back();
		    sort(v.begin(),v.end());
		    return v;
		    
		    
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends